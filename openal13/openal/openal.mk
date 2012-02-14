##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=openal
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "F:\openal-soft-1.13\openal"
ProjectPath            := "F:\openal-soft-1.13\openal"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=shanfl
Date                   :=2012-2-14
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="F:\openal-soft-1.13\openal\openal.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
CmpOptions             := -g $(Preprocessors)
C_CmpOptions           := -g $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
LibPath                := $(LibraryPathSwitch). 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects=$(IntermediateDirectory)/OpenAL32_alAuxEffectSlot$(ObjectSuffix) $(IntermediateDirectory)/OpenAL32_alBuffer$(ObjectSuffix) $(IntermediateDirectory)/OpenAL32_alDatabuffer$(ObjectSuffix) $(IntermediateDirectory)/OpenAL32_alEffect$(ObjectSuffix) $(IntermediateDirectory)/OpenAL32_alError$(ObjectSuffix) $(IntermediateDirectory)/OpenAL32_alExtension$(ObjectSuffix) $(IntermediateDirectory)/OpenAL32_alFilter$(ObjectSuffix) $(IntermediateDirectory)/OpenAL32_alListener$(ObjectSuffix) $(IntermediateDirectory)/OpenAL32_alSource$(ObjectSuffix) $(IntermediateDirectory)/OpenAL32_alState$(ObjectSuffix) \
	$(IntermediateDirectory)/OpenAL32_alThunk$(ObjectSuffix) $(IntermediateDirectory)/src_alutBufferData$(ObjectSuffix) $(IntermediateDirectory)/src_alutCodec$(ObjectSuffix) $(IntermediateDirectory)/src_alutError$(ObjectSuffix) $(IntermediateDirectory)/src_alutInit$(ObjectSuffix) $(IntermediateDirectory)/src_alutInputStream$(ObjectSuffix) $(IntermediateDirectory)/src_alutLoader$(ObjectSuffix) $(IntermediateDirectory)/src_alutOutputStream$(ObjectSuffix) $(IntermediateDirectory)/src_alutUtil$(ObjectSuffix) $(IntermediateDirectory)/src_alutVersion$(ObjectSuffix) \
	$(IntermediateDirectory)/src_alutWaveform$(ObjectSuffix) $(IntermediateDirectory)/Alc_ALc$(ObjectSuffix) $(IntermediateDirectory)/Alc_alcConfig$(ObjectSuffix) $(IntermediateDirectory)/Alc_alcEcho$(ObjectSuffix) $(IntermediateDirectory)/Alc_alcModulator$(ObjectSuffix) $(IntermediateDirectory)/Alc_alcReverb$(ObjectSuffix) $(IntermediateDirectory)/Alc_alcRing$(ObjectSuffix) $(IntermediateDirectory)/Alc_alcThread$(ObjectSuffix) $(IntermediateDirectory)/Alc_alsa$(ObjectSuffix) $(IntermediateDirectory)/Alc_ALu$(ObjectSuffix) \
	$(IntermediateDirectory)/Alc_bs2b$(ObjectSuffix) $(IntermediateDirectory)/Alc_dsound$(ObjectSuffix) $(IntermediateDirectory)/Alc_mixer$(ObjectSuffix) $(IntermediateDirectory)/Alc_null$(ObjectSuffix) $(IntermediateDirectory)/Alc_oss$(ObjectSuffix) $(IntermediateDirectory)/Alc_panning$(ObjectSuffix) $(IntermediateDirectory)/Alc_portaudio$(ObjectSuffix) $(IntermediateDirectory)/Alc_pulseaudio$(ObjectSuffix) $(IntermediateDirectory)/Alc_solaris$(ObjectSuffix) $(IntermediateDirectory)/Alc_wave$(ObjectSuffix) \
	$(IntermediateDirectory)/Alc_winmm$(ObjectSuffix) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects) > $(ObjectsFileList)
	$(ArchiveTool) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList)
	@$(MakeDirCommand) "F:\openal-soft-1.13\openal\.build-debug"
	@echo rebuilt > "F:\openal-soft-1.13\openal\.build-debug\openal"

./Debug:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/OpenAL32_alAuxEffectSlot$(ObjectSuffix): ../OpenAL32/alAuxEffectSlot.c $(IntermediateDirectory)/OpenAL32_alAuxEffectSlot$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/OpenAL32/alAuxEffectSlot.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OpenAL32_alAuxEffectSlot$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenAL32_alAuxEffectSlot$(DependSuffix): ../OpenAL32/alAuxEffectSlot.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenAL32_alAuxEffectSlot$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenAL32_alAuxEffectSlot$(DependSuffix) -MM "F:/openal-soft-1.13/OpenAL32/alAuxEffectSlot.c"

$(IntermediateDirectory)/OpenAL32_alAuxEffectSlot$(PreprocessSuffix): ../OpenAL32/alAuxEffectSlot.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenAL32_alAuxEffectSlot$(PreprocessSuffix) "F:/openal-soft-1.13/OpenAL32/alAuxEffectSlot.c"

$(IntermediateDirectory)/OpenAL32_alBuffer$(ObjectSuffix): ../OpenAL32/alBuffer.c $(IntermediateDirectory)/OpenAL32_alBuffer$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/OpenAL32/alBuffer.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OpenAL32_alBuffer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenAL32_alBuffer$(DependSuffix): ../OpenAL32/alBuffer.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenAL32_alBuffer$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenAL32_alBuffer$(DependSuffix) -MM "F:/openal-soft-1.13/OpenAL32/alBuffer.c"

$(IntermediateDirectory)/OpenAL32_alBuffer$(PreprocessSuffix): ../OpenAL32/alBuffer.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenAL32_alBuffer$(PreprocessSuffix) "F:/openal-soft-1.13/OpenAL32/alBuffer.c"

$(IntermediateDirectory)/OpenAL32_alDatabuffer$(ObjectSuffix): ../OpenAL32/alDatabuffer.c $(IntermediateDirectory)/OpenAL32_alDatabuffer$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/OpenAL32/alDatabuffer.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OpenAL32_alDatabuffer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenAL32_alDatabuffer$(DependSuffix): ../OpenAL32/alDatabuffer.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenAL32_alDatabuffer$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenAL32_alDatabuffer$(DependSuffix) -MM "F:/openal-soft-1.13/OpenAL32/alDatabuffer.c"

$(IntermediateDirectory)/OpenAL32_alDatabuffer$(PreprocessSuffix): ../OpenAL32/alDatabuffer.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenAL32_alDatabuffer$(PreprocessSuffix) "F:/openal-soft-1.13/OpenAL32/alDatabuffer.c"

$(IntermediateDirectory)/OpenAL32_alEffect$(ObjectSuffix): ../OpenAL32/alEffect.c $(IntermediateDirectory)/OpenAL32_alEffect$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/OpenAL32/alEffect.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OpenAL32_alEffect$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenAL32_alEffect$(DependSuffix): ../OpenAL32/alEffect.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenAL32_alEffect$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenAL32_alEffect$(DependSuffix) -MM "F:/openal-soft-1.13/OpenAL32/alEffect.c"

$(IntermediateDirectory)/OpenAL32_alEffect$(PreprocessSuffix): ../OpenAL32/alEffect.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenAL32_alEffect$(PreprocessSuffix) "F:/openal-soft-1.13/OpenAL32/alEffect.c"

$(IntermediateDirectory)/OpenAL32_alError$(ObjectSuffix): ../OpenAL32/alError.c $(IntermediateDirectory)/OpenAL32_alError$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/OpenAL32/alError.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OpenAL32_alError$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenAL32_alError$(DependSuffix): ../OpenAL32/alError.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenAL32_alError$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenAL32_alError$(DependSuffix) -MM "F:/openal-soft-1.13/OpenAL32/alError.c"

$(IntermediateDirectory)/OpenAL32_alError$(PreprocessSuffix): ../OpenAL32/alError.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenAL32_alError$(PreprocessSuffix) "F:/openal-soft-1.13/OpenAL32/alError.c"

$(IntermediateDirectory)/OpenAL32_alExtension$(ObjectSuffix): ../OpenAL32/alExtension.c $(IntermediateDirectory)/OpenAL32_alExtension$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/OpenAL32/alExtension.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OpenAL32_alExtension$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenAL32_alExtension$(DependSuffix): ../OpenAL32/alExtension.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenAL32_alExtension$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenAL32_alExtension$(DependSuffix) -MM "F:/openal-soft-1.13/OpenAL32/alExtension.c"

$(IntermediateDirectory)/OpenAL32_alExtension$(PreprocessSuffix): ../OpenAL32/alExtension.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenAL32_alExtension$(PreprocessSuffix) "F:/openal-soft-1.13/OpenAL32/alExtension.c"

$(IntermediateDirectory)/OpenAL32_alFilter$(ObjectSuffix): ../OpenAL32/alFilter.c $(IntermediateDirectory)/OpenAL32_alFilter$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/OpenAL32/alFilter.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OpenAL32_alFilter$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenAL32_alFilter$(DependSuffix): ../OpenAL32/alFilter.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenAL32_alFilter$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenAL32_alFilter$(DependSuffix) -MM "F:/openal-soft-1.13/OpenAL32/alFilter.c"

$(IntermediateDirectory)/OpenAL32_alFilter$(PreprocessSuffix): ../OpenAL32/alFilter.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenAL32_alFilter$(PreprocessSuffix) "F:/openal-soft-1.13/OpenAL32/alFilter.c"

$(IntermediateDirectory)/OpenAL32_alListener$(ObjectSuffix): ../OpenAL32/alListener.c $(IntermediateDirectory)/OpenAL32_alListener$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/OpenAL32/alListener.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OpenAL32_alListener$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenAL32_alListener$(DependSuffix): ../OpenAL32/alListener.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenAL32_alListener$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenAL32_alListener$(DependSuffix) -MM "F:/openal-soft-1.13/OpenAL32/alListener.c"

$(IntermediateDirectory)/OpenAL32_alListener$(PreprocessSuffix): ../OpenAL32/alListener.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenAL32_alListener$(PreprocessSuffix) "F:/openal-soft-1.13/OpenAL32/alListener.c"

$(IntermediateDirectory)/OpenAL32_alSource$(ObjectSuffix): ../OpenAL32/alSource.c $(IntermediateDirectory)/OpenAL32_alSource$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/OpenAL32/alSource.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OpenAL32_alSource$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenAL32_alSource$(DependSuffix): ../OpenAL32/alSource.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenAL32_alSource$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenAL32_alSource$(DependSuffix) -MM "F:/openal-soft-1.13/OpenAL32/alSource.c"

$(IntermediateDirectory)/OpenAL32_alSource$(PreprocessSuffix): ../OpenAL32/alSource.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenAL32_alSource$(PreprocessSuffix) "F:/openal-soft-1.13/OpenAL32/alSource.c"

$(IntermediateDirectory)/OpenAL32_alState$(ObjectSuffix): ../OpenAL32/alState.c $(IntermediateDirectory)/OpenAL32_alState$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/OpenAL32/alState.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OpenAL32_alState$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenAL32_alState$(DependSuffix): ../OpenAL32/alState.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenAL32_alState$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenAL32_alState$(DependSuffix) -MM "F:/openal-soft-1.13/OpenAL32/alState.c"

$(IntermediateDirectory)/OpenAL32_alState$(PreprocessSuffix): ../OpenAL32/alState.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenAL32_alState$(PreprocessSuffix) "F:/openal-soft-1.13/OpenAL32/alState.c"

$(IntermediateDirectory)/OpenAL32_alThunk$(ObjectSuffix): ../OpenAL32/alThunk.c $(IntermediateDirectory)/OpenAL32_alThunk$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/OpenAL32/alThunk.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OpenAL32_alThunk$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenAL32_alThunk$(DependSuffix): ../OpenAL32/alThunk.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenAL32_alThunk$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenAL32_alThunk$(DependSuffix) -MM "F:/openal-soft-1.13/OpenAL32/alThunk.c"

$(IntermediateDirectory)/OpenAL32_alThunk$(PreprocessSuffix): ../OpenAL32/alThunk.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenAL32_alThunk$(PreprocessSuffix) "F:/openal-soft-1.13/OpenAL32/alThunk.c"

$(IntermediateDirectory)/src_alutBufferData$(ObjectSuffix): ../freealut/src/alutBufferData.c $(IntermediateDirectory)/src_alutBufferData$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/freealut/src/alutBufferData.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_alutBufferData$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_alutBufferData$(DependSuffix): ../freealut/src/alutBufferData.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_alutBufferData$(ObjectSuffix) -MF$(IntermediateDirectory)/src_alutBufferData$(DependSuffix) -MM "F:/openal-soft-1.13/freealut/src/alutBufferData.c"

$(IntermediateDirectory)/src_alutBufferData$(PreprocessSuffix): ../freealut/src/alutBufferData.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_alutBufferData$(PreprocessSuffix) "F:/openal-soft-1.13/freealut/src/alutBufferData.c"

$(IntermediateDirectory)/src_alutCodec$(ObjectSuffix): ../freealut/src/alutCodec.c $(IntermediateDirectory)/src_alutCodec$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/freealut/src/alutCodec.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_alutCodec$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_alutCodec$(DependSuffix): ../freealut/src/alutCodec.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_alutCodec$(ObjectSuffix) -MF$(IntermediateDirectory)/src_alutCodec$(DependSuffix) -MM "F:/openal-soft-1.13/freealut/src/alutCodec.c"

$(IntermediateDirectory)/src_alutCodec$(PreprocessSuffix): ../freealut/src/alutCodec.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_alutCodec$(PreprocessSuffix) "F:/openal-soft-1.13/freealut/src/alutCodec.c"

$(IntermediateDirectory)/src_alutError$(ObjectSuffix): ../freealut/src/alutError.c $(IntermediateDirectory)/src_alutError$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/freealut/src/alutError.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_alutError$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_alutError$(DependSuffix): ../freealut/src/alutError.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_alutError$(ObjectSuffix) -MF$(IntermediateDirectory)/src_alutError$(DependSuffix) -MM "F:/openal-soft-1.13/freealut/src/alutError.c"

$(IntermediateDirectory)/src_alutError$(PreprocessSuffix): ../freealut/src/alutError.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_alutError$(PreprocessSuffix) "F:/openal-soft-1.13/freealut/src/alutError.c"

$(IntermediateDirectory)/src_alutInit$(ObjectSuffix): ../freealut/src/alutInit.c $(IntermediateDirectory)/src_alutInit$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/freealut/src/alutInit.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_alutInit$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_alutInit$(DependSuffix): ../freealut/src/alutInit.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_alutInit$(ObjectSuffix) -MF$(IntermediateDirectory)/src_alutInit$(DependSuffix) -MM "F:/openal-soft-1.13/freealut/src/alutInit.c"

$(IntermediateDirectory)/src_alutInit$(PreprocessSuffix): ../freealut/src/alutInit.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_alutInit$(PreprocessSuffix) "F:/openal-soft-1.13/freealut/src/alutInit.c"

$(IntermediateDirectory)/src_alutInputStream$(ObjectSuffix): ../freealut/src/alutInputStream.c $(IntermediateDirectory)/src_alutInputStream$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/freealut/src/alutInputStream.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_alutInputStream$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_alutInputStream$(DependSuffix): ../freealut/src/alutInputStream.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_alutInputStream$(ObjectSuffix) -MF$(IntermediateDirectory)/src_alutInputStream$(DependSuffix) -MM "F:/openal-soft-1.13/freealut/src/alutInputStream.c"

$(IntermediateDirectory)/src_alutInputStream$(PreprocessSuffix): ../freealut/src/alutInputStream.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_alutInputStream$(PreprocessSuffix) "F:/openal-soft-1.13/freealut/src/alutInputStream.c"

$(IntermediateDirectory)/src_alutLoader$(ObjectSuffix): ../freealut/src/alutLoader.c $(IntermediateDirectory)/src_alutLoader$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/freealut/src/alutLoader.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_alutLoader$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_alutLoader$(DependSuffix): ../freealut/src/alutLoader.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_alutLoader$(ObjectSuffix) -MF$(IntermediateDirectory)/src_alutLoader$(DependSuffix) -MM "F:/openal-soft-1.13/freealut/src/alutLoader.c"

$(IntermediateDirectory)/src_alutLoader$(PreprocessSuffix): ../freealut/src/alutLoader.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_alutLoader$(PreprocessSuffix) "F:/openal-soft-1.13/freealut/src/alutLoader.c"

$(IntermediateDirectory)/src_alutOutputStream$(ObjectSuffix): ../freealut/src/alutOutputStream.c $(IntermediateDirectory)/src_alutOutputStream$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/freealut/src/alutOutputStream.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_alutOutputStream$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_alutOutputStream$(DependSuffix): ../freealut/src/alutOutputStream.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_alutOutputStream$(ObjectSuffix) -MF$(IntermediateDirectory)/src_alutOutputStream$(DependSuffix) -MM "F:/openal-soft-1.13/freealut/src/alutOutputStream.c"

$(IntermediateDirectory)/src_alutOutputStream$(PreprocessSuffix): ../freealut/src/alutOutputStream.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_alutOutputStream$(PreprocessSuffix) "F:/openal-soft-1.13/freealut/src/alutOutputStream.c"

$(IntermediateDirectory)/src_alutUtil$(ObjectSuffix): ../freealut/src/alutUtil.c $(IntermediateDirectory)/src_alutUtil$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/freealut/src/alutUtil.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_alutUtil$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_alutUtil$(DependSuffix): ../freealut/src/alutUtil.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_alutUtil$(ObjectSuffix) -MF$(IntermediateDirectory)/src_alutUtil$(DependSuffix) -MM "F:/openal-soft-1.13/freealut/src/alutUtil.c"

$(IntermediateDirectory)/src_alutUtil$(PreprocessSuffix): ../freealut/src/alutUtil.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_alutUtil$(PreprocessSuffix) "F:/openal-soft-1.13/freealut/src/alutUtil.c"

$(IntermediateDirectory)/src_alutVersion$(ObjectSuffix): ../freealut/src/alutVersion.c $(IntermediateDirectory)/src_alutVersion$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/freealut/src/alutVersion.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_alutVersion$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_alutVersion$(DependSuffix): ../freealut/src/alutVersion.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_alutVersion$(ObjectSuffix) -MF$(IntermediateDirectory)/src_alutVersion$(DependSuffix) -MM "F:/openal-soft-1.13/freealut/src/alutVersion.c"

$(IntermediateDirectory)/src_alutVersion$(PreprocessSuffix): ../freealut/src/alutVersion.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_alutVersion$(PreprocessSuffix) "F:/openal-soft-1.13/freealut/src/alutVersion.c"

$(IntermediateDirectory)/src_alutWaveform$(ObjectSuffix): ../freealut/src/alutWaveform.c $(IntermediateDirectory)/src_alutWaveform$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/freealut/src/alutWaveform.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_alutWaveform$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_alutWaveform$(DependSuffix): ../freealut/src/alutWaveform.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_alutWaveform$(ObjectSuffix) -MF$(IntermediateDirectory)/src_alutWaveform$(DependSuffix) -MM "F:/openal-soft-1.13/freealut/src/alutWaveform.c"

$(IntermediateDirectory)/src_alutWaveform$(PreprocessSuffix): ../freealut/src/alutWaveform.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_alutWaveform$(PreprocessSuffix) "F:/openal-soft-1.13/freealut/src/alutWaveform.c"

$(IntermediateDirectory)/Alc_ALc$(ObjectSuffix): ../Alc/ALc.c $(IntermediateDirectory)/Alc_ALc$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/ALc.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_ALc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_ALc$(DependSuffix): ../Alc/ALc.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_ALc$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_ALc$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/ALc.c"

$(IntermediateDirectory)/Alc_ALc$(PreprocessSuffix): ../Alc/ALc.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_ALc$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/ALc.c"

$(IntermediateDirectory)/Alc_alcConfig$(ObjectSuffix): ../Alc/alcConfig.c $(IntermediateDirectory)/Alc_alcConfig$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/alcConfig.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_alcConfig$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_alcConfig$(DependSuffix): ../Alc/alcConfig.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_alcConfig$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_alcConfig$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/alcConfig.c"

$(IntermediateDirectory)/Alc_alcConfig$(PreprocessSuffix): ../Alc/alcConfig.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_alcConfig$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/alcConfig.c"

$(IntermediateDirectory)/Alc_alcEcho$(ObjectSuffix): ../Alc/alcEcho.c $(IntermediateDirectory)/Alc_alcEcho$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/alcEcho.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_alcEcho$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_alcEcho$(DependSuffix): ../Alc/alcEcho.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_alcEcho$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_alcEcho$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/alcEcho.c"

$(IntermediateDirectory)/Alc_alcEcho$(PreprocessSuffix): ../Alc/alcEcho.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_alcEcho$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/alcEcho.c"

$(IntermediateDirectory)/Alc_alcModulator$(ObjectSuffix): ../Alc/alcModulator.c $(IntermediateDirectory)/Alc_alcModulator$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/alcModulator.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_alcModulator$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_alcModulator$(DependSuffix): ../Alc/alcModulator.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_alcModulator$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_alcModulator$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/alcModulator.c"

$(IntermediateDirectory)/Alc_alcModulator$(PreprocessSuffix): ../Alc/alcModulator.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_alcModulator$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/alcModulator.c"

$(IntermediateDirectory)/Alc_alcReverb$(ObjectSuffix): ../Alc/alcReverb.c $(IntermediateDirectory)/Alc_alcReverb$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/alcReverb.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_alcReverb$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_alcReverb$(DependSuffix): ../Alc/alcReverb.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_alcReverb$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_alcReverb$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/alcReverb.c"

$(IntermediateDirectory)/Alc_alcReverb$(PreprocessSuffix): ../Alc/alcReverb.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_alcReverb$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/alcReverb.c"

$(IntermediateDirectory)/Alc_alcRing$(ObjectSuffix): ../Alc/alcRing.c $(IntermediateDirectory)/Alc_alcRing$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/alcRing.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_alcRing$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_alcRing$(DependSuffix): ../Alc/alcRing.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_alcRing$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_alcRing$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/alcRing.c"

$(IntermediateDirectory)/Alc_alcRing$(PreprocessSuffix): ../Alc/alcRing.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_alcRing$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/alcRing.c"

$(IntermediateDirectory)/Alc_alcThread$(ObjectSuffix): ../Alc/alcThread.c $(IntermediateDirectory)/Alc_alcThread$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/alcThread.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_alcThread$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_alcThread$(DependSuffix): ../Alc/alcThread.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_alcThread$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_alcThread$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/alcThread.c"

$(IntermediateDirectory)/Alc_alcThread$(PreprocessSuffix): ../Alc/alcThread.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_alcThread$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/alcThread.c"

$(IntermediateDirectory)/Alc_alsa$(ObjectSuffix): ../Alc/alsa.c $(IntermediateDirectory)/Alc_alsa$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/alsa.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_alsa$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_alsa$(DependSuffix): ../Alc/alsa.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_alsa$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_alsa$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/alsa.c"

$(IntermediateDirectory)/Alc_alsa$(PreprocessSuffix): ../Alc/alsa.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_alsa$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/alsa.c"

$(IntermediateDirectory)/Alc_ALu$(ObjectSuffix): ../Alc/ALu.c $(IntermediateDirectory)/Alc_ALu$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/ALu.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_ALu$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_ALu$(DependSuffix): ../Alc/ALu.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_ALu$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_ALu$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/ALu.c"

$(IntermediateDirectory)/Alc_ALu$(PreprocessSuffix): ../Alc/ALu.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_ALu$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/ALu.c"

$(IntermediateDirectory)/Alc_bs2b$(ObjectSuffix): ../Alc/bs2b.c $(IntermediateDirectory)/Alc_bs2b$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/bs2b.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_bs2b$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_bs2b$(DependSuffix): ../Alc/bs2b.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_bs2b$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_bs2b$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/bs2b.c"

$(IntermediateDirectory)/Alc_bs2b$(PreprocessSuffix): ../Alc/bs2b.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_bs2b$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/bs2b.c"

$(IntermediateDirectory)/Alc_dsound$(ObjectSuffix): ../Alc/dsound.c $(IntermediateDirectory)/Alc_dsound$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/dsound.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_dsound$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_dsound$(DependSuffix): ../Alc/dsound.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_dsound$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_dsound$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/dsound.c"

$(IntermediateDirectory)/Alc_dsound$(PreprocessSuffix): ../Alc/dsound.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_dsound$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/dsound.c"

$(IntermediateDirectory)/Alc_mixer$(ObjectSuffix): ../Alc/mixer.c $(IntermediateDirectory)/Alc_mixer$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/mixer.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_mixer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_mixer$(DependSuffix): ../Alc/mixer.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_mixer$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_mixer$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/mixer.c"

$(IntermediateDirectory)/Alc_mixer$(PreprocessSuffix): ../Alc/mixer.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_mixer$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/mixer.c"

$(IntermediateDirectory)/Alc_null$(ObjectSuffix): ../Alc/null.c $(IntermediateDirectory)/Alc_null$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/null.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_null$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_null$(DependSuffix): ../Alc/null.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_null$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_null$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/null.c"

$(IntermediateDirectory)/Alc_null$(PreprocessSuffix): ../Alc/null.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_null$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/null.c"

$(IntermediateDirectory)/Alc_oss$(ObjectSuffix): ../Alc/oss.c $(IntermediateDirectory)/Alc_oss$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/oss.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_oss$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_oss$(DependSuffix): ../Alc/oss.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_oss$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_oss$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/oss.c"

$(IntermediateDirectory)/Alc_oss$(PreprocessSuffix): ../Alc/oss.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_oss$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/oss.c"

$(IntermediateDirectory)/Alc_panning$(ObjectSuffix): ../Alc/panning.c $(IntermediateDirectory)/Alc_panning$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/panning.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_panning$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_panning$(DependSuffix): ../Alc/panning.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_panning$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_panning$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/panning.c"

$(IntermediateDirectory)/Alc_panning$(PreprocessSuffix): ../Alc/panning.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_panning$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/panning.c"

$(IntermediateDirectory)/Alc_portaudio$(ObjectSuffix): ../Alc/portaudio.c $(IntermediateDirectory)/Alc_portaudio$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/portaudio.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_portaudio$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_portaudio$(DependSuffix): ../Alc/portaudio.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_portaudio$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_portaudio$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/portaudio.c"

$(IntermediateDirectory)/Alc_portaudio$(PreprocessSuffix): ../Alc/portaudio.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_portaudio$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/portaudio.c"

$(IntermediateDirectory)/Alc_pulseaudio$(ObjectSuffix): ../Alc/pulseaudio.c $(IntermediateDirectory)/Alc_pulseaudio$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/pulseaudio.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_pulseaudio$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_pulseaudio$(DependSuffix): ../Alc/pulseaudio.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_pulseaudio$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_pulseaudio$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/pulseaudio.c"

$(IntermediateDirectory)/Alc_pulseaudio$(PreprocessSuffix): ../Alc/pulseaudio.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_pulseaudio$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/pulseaudio.c"

$(IntermediateDirectory)/Alc_solaris$(ObjectSuffix): ../Alc/solaris.c $(IntermediateDirectory)/Alc_solaris$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/solaris.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_solaris$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_solaris$(DependSuffix): ../Alc/solaris.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_solaris$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_solaris$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/solaris.c"

$(IntermediateDirectory)/Alc_solaris$(PreprocessSuffix): ../Alc/solaris.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_solaris$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/solaris.c"

$(IntermediateDirectory)/Alc_wave$(ObjectSuffix): ../Alc/wave.c $(IntermediateDirectory)/Alc_wave$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/wave.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_wave$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_wave$(DependSuffix): ../Alc/wave.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_wave$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_wave$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/wave.c"

$(IntermediateDirectory)/Alc_wave$(PreprocessSuffix): ../Alc/wave.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_wave$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/wave.c"

$(IntermediateDirectory)/Alc_winmm$(ObjectSuffix): ../Alc/winmm.c $(IntermediateDirectory)/Alc_winmm$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "F:/openal-soft-1.13/Alc/winmm.c" $(C_CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Alc_winmm$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Alc_winmm$(DependSuffix): ../Alc/winmm.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Alc_winmm$(ObjectSuffix) -MF$(IntermediateDirectory)/Alc_winmm$(DependSuffix) -MM "F:/openal-soft-1.13/Alc/winmm.c"

$(IntermediateDirectory)/Alc_winmm$(PreprocessSuffix): ../Alc/winmm.c
	@$(C_CompilerName) $(C_CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Alc_winmm$(PreprocessSuffix) "F:/openal-soft-1.13/Alc/winmm.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/OpenAL32_alAuxEffectSlot$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alAuxEffectSlot$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alAuxEffectSlot$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alBuffer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alBuffer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alBuffer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alDatabuffer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alDatabuffer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alDatabuffer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alEffect$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alEffect$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alEffect$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alError$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alError$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alError$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alExtension$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alExtension$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alExtension$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alFilter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alFilter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alFilter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alListener$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alListener$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alListener$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alSource$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alSource$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alSource$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alState$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alState$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alState$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alThunk$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alThunk$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OpenAL32_alThunk$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_alutBufferData$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_alutBufferData$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_alutBufferData$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_alutCodec$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_alutCodec$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_alutCodec$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_alutError$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_alutError$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_alutError$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_alutInit$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_alutInit$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_alutInit$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_alutInputStream$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_alutInputStream$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_alutInputStream$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_alutLoader$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_alutLoader$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_alutLoader$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_alutOutputStream$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_alutOutputStream$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_alutOutputStream$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_alutUtil$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_alutUtil$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_alutUtil$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_alutVersion$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_alutVersion$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_alutVersion$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_alutWaveform$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_alutWaveform$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_alutWaveform$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_ALc$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_ALc$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_ALc$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcConfig$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcConfig$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcConfig$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcEcho$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcEcho$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcEcho$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcModulator$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcModulator$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcModulator$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcReverb$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcReverb$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcReverb$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcRing$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcRing$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcRing$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcThread$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcThread$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alcThread$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alsa$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alsa$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_alsa$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_ALu$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_ALu$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_ALu$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_bs2b$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_bs2b$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_bs2b$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_dsound$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_dsound$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_dsound$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_mixer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_mixer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_mixer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_null$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_null$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_null$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_oss$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_oss$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_oss$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_panning$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_panning$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_panning$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_portaudio$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_portaudio$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_portaudio$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_pulseaudio$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_pulseaudio$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_pulseaudio$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_solaris$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_solaris$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_solaris$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_wave$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_wave$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_wave$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Alc_winmm$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Alc_winmm$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Alc_winmm$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)
	$(RM) "F:\openal-soft-1.13\openal\.build-debug\openal"


