##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Xbox360
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/YasminPaz/Documents/PROG2
ProjectPath            :=C:/Users/YasminPaz/Documents/PROG2/Xbox360
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=YasminPaz
Date                   :=28/03/2016
CodeLitePath           :="C:/Program Files (x86)/CodeLite"
LinkerName             :=C:/MinGW-4.6.1/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW-4.6.1/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Xbox360.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW-4.6.1/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW-4.6.1/bin/ar.exe rcu
CXX      := C:/MinGW-4.6.1/bin/g++.exe
CC       := C:/MinGW-4.6.1/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-4.6.1/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/ProjetoCpp_Console.cpp$(ObjectSuffix) $(IntermediateDirectory)/ProjetoCpp_Date.cpp$(ObjectSuffix) $(IntermediateDirectory)/ProjetoCpp_Device.cpp$(ObjectSuffix) $(IntermediateDirectory)/ProjetoCpp_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/ProjetoCpp_Xbox360.cpp$(ObjectSuffix) $(IntermediateDirectory)/ProjetoCpp_Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/ProjetoCpp_User.cpp$(ObjectSuffix) $(IntermediateDirectory)/ProjetoCpp_Controller.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/ProjetoCpp_Console.cpp$(ObjectSuffix): ProjetoCpp/Console.cpp $(IntermediateDirectory)/ProjetoCpp_Console.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/YasminPaz/Documents/PROG2/Xbox360/ProjetoCpp/Console.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ProjetoCpp_Console.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ProjetoCpp_Console.cpp$(DependSuffix): ProjetoCpp/Console.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ProjetoCpp_Console.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ProjetoCpp_Console.cpp$(DependSuffix) -MM "ProjetoCpp/Console.cpp"

$(IntermediateDirectory)/ProjetoCpp_Console.cpp$(PreprocessSuffix): ProjetoCpp/Console.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ProjetoCpp_Console.cpp$(PreprocessSuffix) "ProjetoCpp/Console.cpp"

$(IntermediateDirectory)/ProjetoCpp_Date.cpp$(ObjectSuffix): ProjetoCpp/Date.cpp $(IntermediateDirectory)/ProjetoCpp_Date.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/YasminPaz/Documents/PROG2/Xbox360/ProjetoCpp/Date.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ProjetoCpp_Date.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ProjetoCpp_Date.cpp$(DependSuffix): ProjetoCpp/Date.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ProjetoCpp_Date.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ProjetoCpp_Date.cpp$(DependSuffix) -MM "ProjetoCpp/Date.cpp"

$(IntermediateDirectory)/ProjetoCpp_Date.cpp$(PreprocessSuffix): ProjetoCpp/Date.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ProjetoCpp_Date.cpp$(PreprocessSuffix) "ProjetoCpp/Date.cpp"

$(IntermediateDirectory)/ProjetoCpp_Device.cpp$(ObjectSuffix): ProjetoCpp/Device.cpp $(IntermediateDirectory)/ProjetoCpp_Device.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/YasminPaz/Documents/PROG2/Xbox360/ProjetoCpp/Device.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ProjetoCpp_Device.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ProjetoCpp_Device.cpp$(DependSuffix): ProjetoCpp/Device.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ProjetoCpp_Device.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ProjetoCpp_Device.cpp$(DependSuffix) -MM "ProjetoCpp/Device.cpp"

$(IntermediateDirectory)/ProjetoCpp_Device.cpp$(PreprocessSuffix): ProjetoCpp/Device.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ProjetoCpp_Device.cpp$(PreprocessSuffix) "ProjetoCpp/Device.cpp"

$(IntermediateDirectory)/ProjetoCpp_main.cpp$(ObjectSuffix): ProjetoCpp/main.cpp $(IntermediateDirectory)/ProjetoCpp_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/YasminPaz/Documents/PROG2/Xbox360/ProjetoCpp/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ProjetoCpp_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ProjetoCpp_main.cpp$(DependSuffix): ProjetoCpp/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ProjetoCpp_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ProjetoCpp_main.cpp$(DependSuffix) -MM "ProjetoCpp/main.cpp"

$(IntermediateDirectory)/ProjetoCpp_main.cpp$(PreprocessSuffix): ProjetoCpp/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ProjetoCpp_main.cpp$(PreprocessSuffix) "ProjetoCpp/main.cpp"

$(IntermediateDirectory)/ProjetoCpp_Xbox360.cpp$(ObjectSuffix): ProjetoCpp/Xbox360.cpp $(IntermediateDirectory)/ProjetoCpp_Xbox360.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/YasminPaz/Documents/PROG2/Xbox360/ProjetoCpp/Xbox360.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ProjetoCpp_Xbox360.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ProjetoCpp_Xbox360.cpp$(DependSuffix): ProjetoCpp/Xbox360.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ProjetoCpp_Xbox360.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ProjetoCpp_Xbox360.cpp$(DependSuffix) -MM "ProjetoCpp/Xbox360.cpp"

$(IntermediateDirectory)/ProjetoCpp_Xbox360.cpp$(PreprocessSuffix): ProjetoCpp/Xbox360.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ProjetoCpp_Xbox360.cpp$(PreprocessSuffix) "ProjetoCpp/Xbox360.cpp"

$(IntermediateDirectory)/ProjetoCpp_Game.cpp$(ObjectSuffix): ProjetoCpp/Game.cpp $(IntermediateDirectory)/ProjetoCpp_Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/YasminPaz/Documents/PROG2/Xbox360/ProjetoCpp/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ProjetoCpp_Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ProjetoCpp_Game.cpp$(DependSuffix): ProjetoCpp/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ProjetoCpp_Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ProjetoCpp_Game.cpp$(DependSuffix) -MM "ProjetoCpp/Game.cpp"

$(IntermediateDirectory)/ProjetoCpp_Game.cpp$(PreprocessSuffix): ProjetoCpp/Game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ProjetoCpp_Game.cpp$(PreprocessSuffix) "ProjetoCpp/Game.cpp"

$(IntermediateDirectory)/ProjetoCpp_User.cpp$(ObjectSuffix): ProjetoCpp/User.cpp $(IntermediateDirectory)/ProjetoCpp_User.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/YasminPaz/Documents/PROG2/Xbox360/ProjetoCpp/User.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ProjetoCpp_User.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ProjetoCpp_User.cpp$(DependSuffix): ProjetoCpp/User.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ProjetoCpp_User.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ProjetoCpp_User.cpp$(DependSuffix) -MM "ProjetoCpp/User.cpp"

$(IntermediateDirectory)/ProjetoCpp_User.cpp$(PreprocessSuffix): ProjetoCpp/User.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ProjetoCpp_User.cpp$(PreprocessSuffix) "ProjetoCpp/User.cpp"

$(IntermediateDirectory)/ProjetoCpp_Controller.cpp$(ObjectSuffix): ProjetoCpp/Controller.cpp $(IntermediateDirectory)/ProjetoCpp_Controller.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/YasminPaz/Documents/PROG2/Xbox360/ProjetoCpp/Controller.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ProjetoCpp_Controller.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ProjetoCpp_Controller.cpp$(DependSuffix): ProjetoCpp/Controller.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ProjetoCpp_Controller.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ProjetoCpp_Controller.cpp$(DependSuffix) -MM "ProjetoCpp/Controller.cpp"

$(IntermediateDirectory)/ProjetoCpp_Controller.cpp$(PreprocessSuffix): ProjetoCpp/Controller.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ProjetoCpp_Controller.cpp$(PreprocessSuffix) "ProjetoCpp/Controller.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


