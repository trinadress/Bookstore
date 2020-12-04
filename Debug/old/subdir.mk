################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../old/ButtonDemo.cpp \
../old/ButtonPanel.cpp \
../old/Choice.cpp \
../old/DemoFrame.cpp 

OBJS += \
./old/ButtonDemo.o \
./old/ButtonPanel.o \
./old/Choice.o \
./old/DemoFrame.o 

CPP_DEPS += \
./old/ButtonDemo.d \
./old/ButtonPanel.d \
./old/Choice.d \
./old/DemoFrame.d 


# Each subdirectory must supply rules for building sources it contributes
old/%.o: ../old/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -o "$@" "$<" -std=c++11 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -I/usr/local/lib/wx/include/gtk3-unicode-3.1 -I/usr/local/include/wx-3.1 -O0 -g3 -Wall -c -fmessage-length=0 `wx-config --cppflags` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"
	@echo 'Finished building: $<'
	@echo ' '


