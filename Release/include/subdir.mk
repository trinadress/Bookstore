################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../include/BookList.cpp \
../include/BookRecord.cpp \
../include/Bookstore.cpp \
../include/InventoryIterator.cpp \
../include/main.cpp 

OBJS += \
./include/BookList.o \
./include/BookRecord.o \
./include/Bookstore.o \
./include/InventoryIterator.o \
./include/main.o 

CPP_DEPS += \
./include/BookList.d \
./include/BookRecord.d \
./include/Bookstore.d \
./include/InventoryIterator.d \
./include/main.d 


# Each subdirectory must supply rules for building sources it contributes
include/%.o: ../include/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -o "$@" "$<" -std=c++11 -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXGTK__ -I/usr/local/lib/wx/include/gtk3-unicode-3.1 -I/usr/local/include/wx-3.1 -O3 -Wall -c -fmessage-length=0 `wx-config --cppflags` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"
	@echo 'Finished building: $<'
	@echo ' '


