# whatever flags you want to pass to the C compiler & linker
AM_CFLAGS = --pedantic -Wall -O3 -Wextra -fPIC
#AM_LDFLAGS = -lm -lpthread -lstk -lasound -loscpack

# die LD flags muessen nach dem Quellcode positioniert werden
LDADD = -L$(abs_top_builddir)/src/configuration/config4cpp/lib \
	-L/usr/local/lib \
	-lm -lpthread -lstk -lasound -loscpack -lconfig4cpp -lncurses

AM_CPPFLAGS = -std=c++11 -O3 -Wextra -D__LINUX_ALSA__ \
	-I$(abs_top_builddir)/src/include \
	-I$(abs_top_builddir)/src/configuration/config4cpp/include \
	-I/usr/local/include/stk -I/usr/local/include/oscpack/


AUTOMAKE_OPTIONS = subdir-objects

# this lists the binaries to produce, the (non-PHONY, binary) targets in
# the previous manual Makefile
bin_PROGRAMS =  store/mdstore kraftmaschine ugentest fliehkraft cmidiin

store_mdstore_SOURCES = store/mdstore.cpp \
	store/CentralStore.cpp \
	store/MessageDataQueue.cpp \
	osc/MessageData.cpp \
	osc/OscInConnector.cpp


kraftmaschine_SOURCES = kraftmaschine.cpp Neonlicht.cpp \
	util/CosineTable.cpp \
	util/IDGenerator.cpp \
	util/Interpolation.cpp \
	util/KeyPressedControl.cpp \
	util/MidiUtil.cpp \
	util/WaveTable.cpp \
	util/WaveWriter.cpp \
	configuration/ConfigurationManager.cpp \
	osc/MessageData.cpp \
	osc/OscInConnector.cpp \
	store/CentralStore.cpp \
	store/MessageDataQueue.cpp \
	spu/NoiseUnit.cpp \
	spu/ArturiaMiniLabUnit.cpp \
	spu/WorkshopSPU.cpp \
	spu/VCOModSPU.cpp \
	spu/ADSRWorkshopSPU.cpp \
	spu/MultiOscillatorSPU.cpp \
	spu/LFOWorkshopSPU.cpp \
	unit/ADSRGen.cpp \
	unit/ADSR-NewGen.cpp \
	unit/AddTwoGen.cpp \
	unit/CosineGen.cpp \
	unit/EGOneStepGen.cpp \
	unit/EGUpDownGen.cpp \
	unit/EnvelopeGen.cpp \
	unit/GatedConstantGen.cpp \
	unit/InvertGen.cpp \
	unit/MidiInputGen.cpp \
	unit/MoogVCFGen.cpp \
	unit/MoogVCFv2Gen.cpp \
	unit/MultiplyGen.cpp \
	unit/MultiplyTwoGen.cpp \
	unit/MultiSwitch5Gen.cpp \
	unit/NoiseGen.cpp \
	unit/NumberGen.cpp \
	unit/OscillatorGen.cpp \
	unit/OnePoleLPFGen.cpp \
	unit/Patch.cpp \
	unit/PhasorGen.cpp \
	unit/Port.cpp \
	unit/PulseGen.cpp \
	unit/ResCutFilterGen.cpp \
	unit/STKAdapterGen.cpp \
	unit/STKBiQuadGen.cpp \
	unit/STKOnePoleGen.cpp \
	unit/STKOneZeroGen.cpp \
	unit/STKTwoPoleGen.cpp \
	unit/STKTwoZeroGen.cpp \
	unit/SawGen.cpp \
	unit/SoundUnit.cpp \
	unit/SquareGen.cpp \
	unit/ThresholdGen.cpp \
	unit/TwoInputMixerGen.cpp \
	unit/UGen.cpp \
	unit/WaveOutGen.cpp

ugentest_SOURCES =  ugentest.cpp \
	util/CosineTable.cpp \
	util/Interpolation.cpp \
	util/IDGenerator.cpp \
	util/KeyPressedControl.cpp \
	util/MidiUtil.cpp \
	util/WaveTable.cpp \
	util/WaveWriter.cpp \
	spu/NoiseUnit.cpp \
	spu/ArturiaMiniLabUnit.cpp \
	spu/WorkshopSPU.cpp \
	spu/VCOModSPU.cpp \
	spu/ADSRWorkshopSPU.cpp \
	spu/MultiOscillatorSPU.cpp \
	spu/LFOWorkshopSPU.cpp \
	unit/ADSRGen.cpp  \
	unit/ADSR-NewGen.cpp \
	unit/AddTwoGen.cpp \
	unit/CosineGen.cpp \
	unit/EGOneStepGen.cpp \
	unit/EGUpDownGen.cpp \
	unit/EnvelopeGen.cpp \
	unit/GatedConstantGen.cpp \
	unit/InvertGen.cpp \
	unit/MidiInputGen.cpp \
	unit/MoogVCFGen.cpp \
	unit/MoogVCFv2Gen.cpp \
	unit/MultiplyGen.cpp \
	unit/MultiplyTwoGen.cpp \
	unit/MultiSwitch5Gen.cpp \
	unit/NoiseGen.cpp \
	unit/NumberGen.cpp \
	unit/OscillatorGen.cpp \
	unit/OnePoleLPFGen.cpp \
	unit/Patch.cpp \
	unit/PhasorGen.cpp \
	unit/Port.cpp \
	unit/PulseGen.cpp \
	unit/ResCutFilterGen.cpp \
	unit/STKAdapterGen.cpp \
	unit/STKBiQuadGen.cpp \
	unit/STKOnePoleGen.cpp \
	unit/STKOneZeroGen.cpp \
	unit/STKTwoPoleGen.cpp \
	unit/STKTwoZeroGen.cpp \
	unit/SawGen.cpp \
	unit/SoundUnit.cpp \
	unit/SquareGen.cpp \
	unit/ThresholdGen.cpp \
	unit/TwoInputMixerGen.cpp \
	unit/UGen.cpp \
	unit/WaveOutGen.cpp 

fliehkraft_SOURCES = sequencer/fliehkraft.cpp \
	sequencer/Pulse.cpp \
	sequencer/Activator.cpp \
	sequencer/OscActivator.cpp \
	osc/OscOutConnector.cpp \
	osc/MidiConnector.cpp \
	gui/GUI.cpp \
	gui/GUIMapping.cpp \
	gui/WorkshopGUI.cpp \
	util/KeyPressedControl.cpp 

cmidiin_SOURCES = cmidiin.cpp \
	osc/MidiConnector.cpp \
	osc/OscOutConnector.cpp \
	gui/GUI.cpp \
	gui/GUIMapping.cpp \
	gui/WorkshopGUI.cpp \
	util/KeyPressedControl.cpp 
