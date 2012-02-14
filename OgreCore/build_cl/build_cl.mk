##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=build_cl
ConfigurationName      :=Release
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "E:\workspace_c\socket\udp"
ProjectPath            := "E:\GameTools\OgreCore\build_cl"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=2012-2-12
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
OutputFile             :=$(IntermediateDirectory)/libOgreTool.a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="E:\GameTools\OgreCore\build_cl\build_cl.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
CmpOptions             :=  $(Preprocessors)
C_CmpOptions           :=  $(Preprocessors)
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
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects=$(IntermediateDirectory)/OgreMemory_OgreAlignedAllocator$(ObjectSuffix) $(IntermediateDirectory)/OgreMemory_OgreMemoryAllocatedObject$(ObjectSuffix) $(IntermediateDirectory)/OgreMemory_OgreMemoryNedAlloc$(ObjectSuffix) $(IntermediateDirectory)/OgreMemory_OgreMemoryNedPooling$(ObjectSuffix) $(IntermediateDirectory)/OgreMemory_OgreMemoryTracker$(ObjectSuffix) $(IntermediateDirectory)/OgreMath_OgreAxisAlignedBox$(ObjectSuffix) $(IntermediateDirectory)/OgreMath_OgreMath$(ObjectSuffix) $(IntermediateDirectory)/OgreMath_OgreMatrix3$(ObjectSuffix) $(IntermediateDirectory)/OgreMath_OgreMatrix4$(ObjectSuffix) $(IntermediateDirectory)/OgreMath_OgrePlane$(ObjectSuffix) \
	$(IntermediateDirectory)/OgreMath_OgreQuaternion$(ObjectSuffix) $(IntermediateDirectory)/OgreMath_OgreVector2$(ObjectSuffix) $(IntermediateDirectory)/OgreMath_OgreVector3$(ObjectSuffix) $(IntermediateDirectory)/OgreMath_OgreVector4$(ObjectSuffix) $(IntermediateDirectory)/OgreString_flString$(ObjectSuffix) $(IntermediateDirectory)/OgreString_OgreUTFString$(ObjectSuffix) $(IntermediateDirectory)/OgreCore_flLog$(ObjectSuffix) $(IntermediateDirectory)/OgreCore_flLogManager$(ObjectSuffix) $(IntermediateDirectory)/OgreCore_OgreDataStream$(ObjectSuffix) $(IntermediateDirectory)/OgreCore_OgreException$(ObjectSuffix) \
	

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
	@$(MakeDirCommand) "E:\workspace_c\socket\udp\.build-release"
	@echo rebuilt > "E:\workspace_c\socket\udp\.build-release\build_cl"

./Release:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/OgreMemory_OgreAlignedAllocator$(ObjectSuffix): ../OgreMemory/OgreAlignedAllocator.cpp $(IntermediateDirectory)/OgreMemory_OgreAlignedAllocator$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMemory/OgreAlignedAllocator.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMemory_OgreAlignedAllocator$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMemory_OgreAlignedAllocator$(DependSuffix): ../OgreMemory/OgreAlignedAllocator.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMemory_OgreAlignedAllocator$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMemory_OgreAlignedAllocator$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMemory/OgreAlignedAllocator.cpp"

$(IntermediateDirectory)/OgreMemory_OgreAlignedAllocator$(PreprocessSuffix): ../OgreMemory/OgreAlignedAllocator.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMemory_OgreAlignedAllocator$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMemory/OgreAlignedAllocator.cpp"

$(IntermediateDirectory)/OgreMemory_OgreMemoryAllocatedObject$(ObjectSuffix): ../OgreMemory/OgreMemoryAllocatedObject.cpp $(IntermediateDirectory)/OgreMemory_OgreMemoryAllocatedObject$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMemory/OgreMemoryAllocatedObject.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMemory_OgreMemoryAllocatedObject$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMemory_OgreMemoryAllocatedObject$(DependSuffix): ../OgreMemory/OgreMemoryAllocatedObject.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMemory_OgreMemoryAllocatedObject$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMemory_OgreMemoryAllocatedObject$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMemory/OgreMemoryAllocatedObject.cpp"

$(IntermediateDirectory)/OgreMemory_OgreMemoryAllocatedObject$(PreprocessSuffix): ../OgreMemory/OgreMemoryAllocatedObject.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMemory_OgreMemoryAllocatedObject$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMemory/OgreMemoryAllocatedObject.cpp"

$(IntermediateDirectory)/OgreMemory_OgreMemoryNedAlloc$(ObjectSuffix): ../OgreMemory/OgreMemoryNedAlloc.cpp $(IntermediateDirectory)/OgreMemory_OgreMemoryNedAlloc$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMemory/OgreMemoryNedAlloc.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMemory_OgreMemoryNedAlloc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMemory_OgreMemoryNedAlloc$(DependSuffix): ../OgreMemory/OgreMemoryNedAlloc.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMemory_OgreMemoryNedAlloc$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMemory_OgreMemoryNedAlloc$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMemory/OgreMemoryNedAlloc.cpp"

$(IntermediateDirectory)/OgreMemory_OgreMemoryNedAlloc$(PreprocessSuffix): ../OgreMemory/OgreMemoryNedAlloc.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMemory_OgreMemoryNedAlloc$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMemory/OgreMemoryNedAlloc.cpp"

$(IntermediateDirectory)/OgreMemory_OgreMemoryNedPooling$(ObjectSuffix): ../OgreMemory/OgreMemoryNedPooling.cpp $(IntermediateDirectory)/OgreMemory_OgreMemoryNedPooling$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMemory/OgreMemoryNedPooling.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMemory_OgreMemoryNedPooling$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMemory_OgreMemoryNedPooling$(DependSuffix): ../OgreMemory/OgreMemoryNedPooling.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMemory_OgreMemoryNedPooling$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMemory_OgreMemoryNedPooling$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMemory/OgreMemoryNedPooling.cpp"

$(IntermediateDirectory)/OgreMemory_OgreMemoryNedPooling$(PreprocessSuffix): ../OgreMemory/OgreMemoryNedPooling.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMemory_OgreMemoryNedPooling$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMemory/OgreMemoryNedPooling.cpp"

$(IntermediateDirectory)/OgreMemory_OgreMemoryTracker$(ObjectSuffix): ../OgreMemory/OgreMemoryTracker.cpp $(IntermediateDirectory)/OgreMemory_OgreMemoryTracker$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMemory/OgreMemoryTracker.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMemory_OgreMemoryTracker$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMemory_OgreMemoryTracker$(DependSuffix): ../OgreMemory/OgreMemoryTracker.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMemory_OgreMemoryTracker$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMemory_OgreMemoryTracker$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMemory/OgreMemoryTracker.cpp"

$(IntermediateDirectory)/OgreMemory_OgreMemoryTracker$(PreprocessSuffix): ../OgreMemory/OgreMemoryTracker.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMemory_OgreMemoryTracker$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMemory/OgreMemoryTracker.cpp"

$(IntermediateDirectory)/OgreMath_OgreAxisAlignedBox$(ObjectSuffix): ../OgreMath/OgreAxisAlignedBox.cpp $(IntermediateDirectory)/OgreMath_OgreAxisAlignedBox$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMath/OgreAxisAlignedBox.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMath_OgreAxisAlignedBox$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMath_OgreAxisAlignedBox$(DependSuffix): ../OgreMath/OgreAxisAlignedBox.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMath_OgreAxisAlignedBox$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMath_OgreAxisAlignedBox$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMath/OgreAxisAlignedBox.cpp"

$(IntermediateDirectory)/OgreMath_OgreAxisAlignedBox$(PreprocessSuffix): ../OgreMath/OgreAxisAlignedBox.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMath_OgreAxisAlignedBox$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMath/OgreAxisAlignedBox.cpp"

$(IntermediateDirectory)/OgreMath_OgreMath$(ObjectSuffix): ../OgreMath/OgreMath.cpp $(IntermediateDirectory)/OgreMath_OgreMath$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMath/OgreMath.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMath_OgreMath$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMath_OgreMath$(DependSuffix): ../OgreMath/OgreMath.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMath_OgreMath$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMath_OgreMath$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMath/OgreMath.cpp"

$(IntermediateDirectory)/OgreMath_OgreMath$(PreprocessSuffix): ../OgreMath/OgreMath.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMath_OgreMath$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMath/OgreMath.cpp"

$(IntermediateDirectory)/OgreMath_OgreMatrix3$(ObjectSuffix): ../OgreMath/OgreMatrix3.cpp $(IntermediateDirectory)/OgreMath_OgreMatrix3$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMath/OgreMatrix3.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMath_OgreMatrix3$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMath_OgreMatrix3$(DependSuffix): ../OgreMath/OgreMatrix3.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMath_OgreMatrix3$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMath_OgreMatrix3$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMath/OgreMatrix3.cpp"

$(IntermediateDirectory)/OgreMath_OgreMatrix3$(PreprocessSuffix): ../OgreMath/OgreMatrix3.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMath_OgreMatrix3$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMath/OgreMatrix3.cpp"

$(IntermediateDirectory)/OgreMath_OgreMatrix4$(ObjectSuffix): ../OgreMath/OgreMatrix4.cpp $(IntermediateDirectory)/OgreMath_OgreMatrix4$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMath/OgreMatrix4.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMath_OgreMatrix4$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMath_OgreMatrix4$(DependSuffix): ../OgreMath/OgreMatrix4.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMath_OgreMatrix4$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMath_OgreMatrix4$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMath/OgreMatrix4.cpp"

$(IntermediateDirectory)/OgreMath_OgreMatrix4$(PreprocessSuffix): ../OgreMath/OgreMatrix4.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMath_OgreMatrix4$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMath/OgreMatrix4.cpp"

$(IntermediateDirectory)/OgreMath_OgrePlane$(ObjectSuffix): ../OgreMath/OgrePlane.cpp $(IntermediateDirectory)/OgreMath_OgrePlane$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMath/OgrePlane.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMath_OgrePlane$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMath_OgrePlane$(DependSuffix): ../OgreMath/OgrePlane.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMath_OgrePlane$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMath_OgrePlane$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMath/OgrePlane.cpp"

$(IntermediateDirectory)/OgreMath_OgrePlane$(PreprocessSuffix): ../OgreMath/OgrePlane.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMath_OgrePlane$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMath/OgrePlane.cpp"

$(IntermediateDirectory)/OgreMath_OgreQuaternion$(ObjectSuffix): ../OgreMath/OgreQuaternion.cpp $(IntermediateDirectory)/OgreMath_OgreQuaternion$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMath/OgreQuaternion.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMath_OgreQuaternion$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMath_OgreQuaternion$(DependSuffix): ../OgreMath/OgreQuaternion.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMath_OgreQuaternion$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMath_OgreQuaternion$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMath/OgreQuaternion.cpp"

$(IntermediateDirectory)/OgreMath_OgreQuaternion$(PreprocessSuffix): ../OgreMath/OgreQuaternion.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMath_OgreQuaternion$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMath/OgreQuaternion.cpp"

$(IntermediateDirectory)/OgreMath_OgreVector2$(ObjectSuffix): ../OgreMath/OgreVector2.cpp $(IntermediateDirectory)/OgreMath_OgreVector2$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMath/OgreVector2.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMath_OgreVector2$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMath_OgreVector2$(DependSuffix): ../OgreMath/OgreVector2.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMath_OgreVector2$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMath_OgreVector2$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMath/OgreVector2.cpp"

$(IntermediateDirectory)/OgreMath_OgreVector2$(PreprocessSuffix): ../OgreMath/OgreVector2.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMath_OgreVector2$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMath/OgreVector2.cpp"

$(IntermediateDirectory)/OgreMath_OgreVector3$(ObjectSuffix): ../OgreMath/OgreVector3.cpp $(IntermediateDirectory)/OgreMath_OgreVector3$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMath/OgreVector3.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMath_OgreVector3$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMath_OgreVector3$(DependSuffix): ../OgreMath/OgreVector3.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMath_OgreVector3$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMath_OgreVector3$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMath/OgreVector3.cpp"

$(IntermediateDirectory)/OgreMath_OgreVector3$(PreprocessSuffix): ../OgreMath/OgreVector3.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMath_OgreVector3$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMath/OgreVector3.cpp"

$(IntermediateDirectory)/OgreMath_OgreVector4$(ObjectSuffix): ../OgreMath/OgreVector4.cpp $(IntermediateDirectory)/OgreMath_OgreVector4$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreMath/OgreVector4.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreMath_OgreVector4$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreMath_OgreVector4$(DependSuffix): ../OgreMath/OgreVector4.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreMath_OgreVector4$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreMath_OgreVector4$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreMath/OgreVector4.cpp"

$(IntermediateDirectory)/OgreMath_OgreVector4$(PreprocessSuffix): ../OgreMath/OgreVector4.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreMath_OgreVector4$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreMath/OgreVector4.cpp"

$(IntermediateDirectory)/OgreString_flString$(ObjectSuffix): ../OgreString/flString.cpp $(IntermediateDirectory)/OgreString_flString$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreString/flString.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreString_flString$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreString_flString$(DependSuffix): ../OgreString/flString.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreString_flString$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreString_flString$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreString/flString.cpp"

$(IntermediateDirectory)/OgreString_flString$(PreprocessSuffix): ../OgreString/flString.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreString_flString$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreString/flString.cpp"

$(IntermediateDirectory)/OgreString_OgreUTFString$(ObjectSuffix): ../OgreString/OgreUTFString.cpp $(IntermediateDirectory)/OgreString_OgreUTFString$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreString/OgreUTFString.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreString_OgreUTFString$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreString_OgreUTFString$(DependSuffix): ../OgreString/OgreUTFString.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreString_OgreUTFString$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreString_OgreUTFString$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreString/OgreUTFString.cpp"

$(IntermediateDirectory)/OgreString_OgreUTFString$(PreprocessSuffix): ../OgreString/OgreUTFString.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreString_OgreUTFString$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreString/OgreUTFString.cpp"

$(IntermediateDirectory)/OgreCore_flLog$(ObjectSuffix): ../flLog.cpp $(IntermediateDirectory)/OgreCore_flLog$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/flLog.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreCore_flLog$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreCore_flLog$(DependSuffix): ../flLog.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreCore_flLog$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreCore_flLog$(DependSuffix) -MM "E:/GameTools/OgreCore/flLog.cpp"

$(IntermediateDirectory)/OgreCore_flLog$(PreprocessSuffix): ../flLog.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreCore_flLog$(PreprocessSuffix) "E:/GameTools/OgreCore/flLog.cpp"

$(IntermediateDirectory)/OgreCore_flLogManager$(ObjectSuffix): ../flLogManager.cpp $(IntermediateDirectory)/OgreCore_flLogManager$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/flLogManager.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreCore_flLogManager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreCore_flLogManager$(DependSuffix): ../flLogManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreCore_flLogManager$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreCore_flLogManager$(DependSuffix) -MM "E:/GameTools/OgreCore/flLogManager.cpp"

$(IntermediateDirectory)/OgreCore_flLogManager$(PreprocessSuffix): ../flLogManager.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreCore_flLogManager$(PreprocessSuffix) "E:/GameTools/OgreCore/flLogManager.cpp"

$(IntermediateDirectory)/OgreCore_OgreDataStream$(ObjectSuffix): ../OgreDataStream.cpp $(IntermediateDirectory)/OgreCore_OgreDataStream$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreDataStream.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreCore_OgreDataStream$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreCore_OgreDataStream$(DependSuffix): ../OgreDataStream.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreCore_OgreDataStream$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreCore_OgreDataStream$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreDataStream.cpp"

$(IntermediateDirectory)/OgreCore_OgreDataStream$(PreprocessSuffix): ../OgreDataStream.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreCore_OgreDataStream$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreDataStream.cpp"

$(IntermediateDirectory)/OgreCore_OgreException$(ObjectSuffix): ../OgreException.cpp $(IntermediateDirectory)/OgreCore_OgreException$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "E:/GameTools/OgreCore/OgreException.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/OgreCore_OgreException$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OgreCore_OgreException$(DependSuffix): ../OgreException.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OgreCore_OgreException$(ObjectSuffix) -MF$(IntermediateDirectory)/OgreCore_OgreException$(DependSuffix) -MM "E:/GameTools/OgreCore/OgreException.cpp"

$(IntermediateDirectory)/OgreCore_OgreException$(PreprocessSuffix): ../OgreException.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OgreCore_OgreException$(PreprocessSuffix) "E:/GameTools/OgreCore/OgreException.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreAlignedAllocator$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreAlignedAllocator$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreAlignedAllocator$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreMemoryAllocatedObject$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreMemoryAllocatedObject$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreMemoryAllocatedObject$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreMemoryNedAlloc$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreMemoryNedAlloc$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreMemoryNedAlloc$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreMemoryNedPooling$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreMemoryNedPooling$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreMemoryNedPooling$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreMemoryTracker$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreMemoryTracker$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMemory_OgreMemoryTracker$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreAxisAlignedBox$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreAxisAlignedBox$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreAxisAlignedBox$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreMath$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreMath$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreMath$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreMatrix3$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreMatrix3$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreMatrix3$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreMatrix4$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreMatrix4$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreMatrix4$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgrePlane$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgrePlane$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgrePlane$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreQuaternion$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreQuaternion$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreQuaternion$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreVector2$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreVector2$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreVector2$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreVector3$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreVector3$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreVector3$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreVector4$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreVector4$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreMath_OgreVector4$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreString_flString$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreString_flString$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreString_flString$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreString_OgreUTFString$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreString_OgreUTFString$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreString_OgreUTFString$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreCore_flLog$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreCore_flLog$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreCore_flLog$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreCore_flLogManager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreCore_flLogManager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreCore_flLogManager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreCore_OgreDataStream$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreCore_OgreDataStream$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreCore_OgreDataStream$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/OgreCore_OgreException$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/OgreCore_OgreException$(DependSuffix)
	$(RM) $(IntermediateDirectory)/OgreCore_OgreException$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)
	$(RM) "E:\workspace_c\socket\udp\.build-release\build_cl"


