################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BookstoreDemo.cpp \
../BookstoreFrame.cpp \
../MainPanel.cpp 

OBJS += \
./BookstoreDemo.o \
./BookstoreFrame.o \
./MainPanel.o 

CPP_DEPS += \
./BookstoreDemo.d \
./BookstoreFrame.d \
./MainPanel.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -o "$@" "$<" -std=c++11 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -I/usr/local/lib/wx/include/gtk3-unicode-3.1 -I/usr/local/include/wx-3.1 -O3 -Wall -c -fmessage-length=0 `wx-config --cppflags` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"
	@echo 'Finished building: $<'
	@echo ' '


