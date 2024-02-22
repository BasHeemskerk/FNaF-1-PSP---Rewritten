TARGET = FNaF
OBJS = source/main.o 			\
source/image.o 					\
source/graphics.o 				\
source/vram.o					\
source/state.o					\
source/disclaimer_basdev.o		\
source/music.o					\
source/ambience.o				\
source/menu.o					\
source/image_loader.o			\
source/image_renderer.o			\
source/audio_effects.o			\
source/scene_builder.o			\
source/input.o					\
source/save_system.o			\
source/game_text.o				\
source/animatronic_manager.o	\
source/freddy.o					\
source/bonnie.o					\
source/chica.o					\
source/foxy.o					\
source/office.o					\
source/camera.o					\
source/thread_id.o				\
source/debug.o					\
source/time_manager.o			\
source/power_manager.o			\
source/game_reset.o				\
#source/image2.o					\
#source/audio.o					\
#source/state.o					\
#source/save.o					\
#source/menu.o					\
#source/newspaper.o				\
#source/nightinfo.o				\
#source/office.o					\
#source/customnight.o			\
3source/power.o					\
#source/camera.o					\
#source/animatronic.o			\
#source/time.o					\
#source/sixam.o					\
#source/dead.o					\
#source/ending.o					\
#source/jumpscare.o				\
#source/powerout.o				


CFLAGS = -O2 -G0 -Wall -g -gdwarf-2
CXXFLAGS = $(CFLAGS) -std=c++14 -fno-rtti
ASFLAGS = $(CFLAGS)

# PSP stuff
BUILD_PRX = 1
#PSP_FW_VERSION = 500
#PSP_LARGE_MEMORY = 1

LIBDIR = ./ include lib $(PSPSDK)/../lib

LIBS += -lpng -lz -ljpeg -lpspgum_vfpu -lpspgu -lpspgum -lpspvfpu -lpspvram -lm	-losl -lpspaudiolib -lpspaudio -lpspaudiocodec -lpspmp3 -lstdc++

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = FNaF 1 PSP v1.4.0 - Rewritten
PSP_EBOOT_ICON = ICON0.PNG
PSP_EBOOT_PIC1 = PIC1.PNG

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak