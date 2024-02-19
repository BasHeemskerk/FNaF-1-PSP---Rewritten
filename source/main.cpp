#include "included/global.hpp"

//disclaimer (hard-coded)
#include "included/disclaimer_basdev.hpp"

//globally used
#include "included/music.hpp"
#include "included/scene_builder.hpp"
#include "included/input.hpp"
#include "included/save_system.hpp"
#include "included/game_text.hpp"
//#include "included/image2.hpp"
//#include "included/audio.hpp"
#include "included/state.hpp"
//#include "included/save.hpp"
//#include "included/power.hpp"
//#include "included/time.hpp"
//#include "included/camera.hpp"

//only for certain areas
//#include "included/menu.hpp"
//#include "included/newspaper.hpp"
//#include "included/nightinfo.hpp"
//#include "included/office.hpp"
//#include "included/customnight.hpp"
//#include "included/sixam.hpp"
//#include "included/dead.hpp"
//#include "included/ending.hpp"
//#include "included/jumpscare.hpp"
//#include "included/powerout.hpp"


#include <cstdlib>

using namespace std;

#define BUF_WIDTH (512)
#define SCR_WIDTH (480)
#define SCR_HEIGHT (272)
#define PIXEL_SIZE (4) 
#define FRAME_SIZE (BUF_WIDTH * SCR_HEIGHT * PIXEL_SIZE)
#define ZBUF_SIZE (BUF_WIDTH SCR_HEIGHT * 2)

PSP_MODULE_INFO("FNaF 1 PSP v1.4.0", 0, 1, 0);

PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-1024);

#if _PSP_FW_VERSION >= 200
PSP_HEAP_SIZE_KB(20480);
#endif

static unsigned int __attribute__((aligned(16))) DisplayList[262144];

int exit_callback(int arg1, int arg2, void* common){
    sceKernelExitGame();
    return 0;
}

int callbackThread(SceSize args, void* argp){
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);

    sceKernelSleepThreadCB();
    return 0;
}

void setupCallbacks(){
    int thid = sceKernelCreateThread("update_thread", callbackThread, 0x11, 0xFA0, 0, NULL);
    if (thid >= 0){
        sceKernelStartThread(thid, 0, NULL);
    }
}

void* fbp0 = NULL;
void* fbp1 = NULL;
void* renderTarget = NULL;
void* zbp = NULL;

void InitGU(){    
    fbp0 = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_8888);
    fbp1 = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_8888);
    zbp = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_4444);

    renderTarget = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_8888);

    sceGuInit();
    sceGuStart(GU_DIRECT,DisplayList);

    sceGuDrawBuffer(GU_PSM_5650,fbp0,BUF_WIDTH);
    sceGuDispBuffer(SCR_WIDTH,SCR_HEIGHT,fbp1,BUF_WIDTH);
    sceGuDepthBuffer(zbp,BUF_WIDTH);

    sceGuDepthRange(65535,0);
    sceGuDepthMask(GU_FALSE);

    sceGuOffset(2048 - (SCR_WIDTH / 2),2048 - (SCR_HEIGHT / 2));

    sceGuViewport(2048,2048,SCR_WIDTH,SCR_HEIGHT);

    sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);

    sceGuScissor(0,0,SCR_WIDTH,SCR_HEIGHT);
    sceGuEnable(GU_SCISSOR_TEST);

    sceGuAlphaFunc(GU_GREATER,0,0xff);
    sceGuEnable(GU_ALPHA_TEST);

    sceGuDepthFunc(GU_GEQUAL);
    sceGuEnable(GU_DEPTH_TEST);

    sceGuFrontFace(GU_CW);

    sceGuTexMode(GU_PSM_5650,0,0,0); 
    sceGuTexFunc(GU_TFX_REPLACE,GU_TCC_RGBA);
    sceGuTexFilter(GU_NEAREST,GU_NEAREST);

    sceGuEnable(GU_CULL_FACE);
    
    sceGuEnable(GU_TEXTURE_2D);

    sceGuEnable(GU_DITHER);

    sceGuEnable(GU_CLIP_PLANES);
    
    sceGuEnable(GU_LIGHTING);
    sceGuEnable(GU_LIGHT0);
    sceGuEnable(GU_LIGHT1);
    sceGuEnable(GU_LIGHT2);
    sceGuEnable(GU_LIGHT3);
    
    sceGuEnable(GU_FOG);

    sceGuEnable(GU_BLEND);
    sceGuBlendFunc(GU_ADD,GU_SRC_ALPHA,GU_ONE_MINUS_SRC_ALPHA,0,0);

    sceGuShadeModel(GU_SMOOTH); 

    sceGuFinish();

    sceGuSync(0,0);

    sceDisplayWaitVblankStart();

    sceGuDisplay(GU_TRUE);
}

void initEngine(){
    setupCallbacks();
    pspDebugScreenInit();

    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    InitGU();

    //oslInit();
    VirtualFileInit();
    oslInitAudio();

    music::load_music_file::init_music_loader();

    //oslSetFramerate(30);
}

bool engine_running = false;

void init_game(){
    if (!engine_running){
        initEngine();
        save_system::initialize::initialize_save_system();
        game_text::global::load_text();
        engine_running = true;
    }
}

void game_loop(){

    input::input();

    if (state::on_disclaimer){
        scene_builder::disclaimer::run_disclaimer_scene();
        //input::set_input_delay(0);

        if (input::ctrlData.Buttons & PSP_CTRL_CROSS){
            state::on_disclaimer = false;
            scene_builder::disclaimer::exit_disclaimer();
            state::on_menu = true;
        }
    }
    if (state::on_menu){
        scene_builder::main_menu::load_main_menu();
        scene_builder::main_menu::create_main_menu_scene();
        scene_builder::main_menu::run_main_menu_scene();
    }
    if (state::on_newspaper){
        scene_builder::newspaper::run_newspaper_scene();
    }
    if (state::on_continue){
        scene_builder::continue_night::run_continue_scene();
    }
    if (state::on_custom_night){
        scene_builder::custom_night::load_custom_night_scene();
        scene_builder::custom_night::run_custom_night_scene();
    }
}

auto main() -> int{

    SceCtrlData ctrlData;

    init_game();
    //disclaimer::init_disclaimer();
    scene_builder::disclaimer::load_disclaimer();

    //float cursorMoveTime = 5;


    while(true){

        sceCtrlReadBufferPositive(&ctrlData, 1);

        //running = isRunning();

        sceGuStart(GU_DIRECT,DisplayList);

        // clear screen

        sceGuClearColor(0x000000);
        sceGuClearDepth(0);
        sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);

        // setup aspect ratio

        sceGumMatrixMode(GU_PROJECTION);
        sceGumLoadIdentity();
        sceGumPerspective(70.0f,16.0f/9.0f,0.5f,1000.0f);
            
            // setup camera
        sceGumMatrixMode(GU_VIEW);
        {
            ScePspFVector3 pos = {0, 0, 0};
            ScePspFVector3 rot = { 0, 0, 0 };

            sceGumLoadIdentity();
            sceGumTranslate(&pos);
            sceGumRotateXYZ(&rot);
        }
        
        sceDisplayWaitVblankStart();

        game_loop();
            
        sceGuFinish();
        sceGuSync(0,0);

        sceGuSwapBuffers();
    }
}