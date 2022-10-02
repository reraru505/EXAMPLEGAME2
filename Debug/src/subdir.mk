################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/AGAME.c \
../src/collman.c \
../src/display.c \
../src/game.c \
../src/resman.c 

C_DEPS += \
./src/AGAME.d \
./src/collman.d \
./src/display.d \
./src/game.d \
./src/resman.d 

OBJS += \
./src/AGAME.o \
./src/collman.o \
./src/display.o \
./src/game.o \
./src/resman.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/fnln/eclipse-workspace/AGAME/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/AGAME.d ./src/AGAME.o ./src/collman.d ./src/collman.o ./src/display.d ./src/display.o ./src/game.d ./src/game.o ./src/resman.d ./src/resman.o

.PHONY: clean-src

