#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile

# Environment
SHELL=cmd.exe
# Adding MPLAB X bin directory to path
PATH:=C:/Program Files (x86)/Microchip/MPLABX/mplab_ide/mplab_ide/modules/../../bin/:$(PATH)
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Pic-usb450.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Pic-usb450.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1362431922/usb_function_hid.o ${OBJECTDIR}/_ext/209253324/usb_device.o ${OBJECTDIR}/_ext/1690398464/usb_descriptors.o ${OBJECTDIR}/main.o ${OBJECTDIR}/1wire.o ${OBJECTDIR}/delay.o ${OBJECTDIR}/LCD_44780.o ${OBJECTDIR}/one-wire.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1362431922/usb_function_hid.o.d ${OBJECTDIR}/_ext/209253324/usb_device.o.d ${OBJECTDIR}/_ext/1690398464/usb_descriptors.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/1wire.o.d ${OBJECTDIR}/delay.o.d ${OBJECTDIR}/LCD_44780.o.d ${OBJECTDIR}/one-wire.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1362431922/usb_function_hid.o ${OBJECTDIR}/_ext/209253324/usb_device.o ${OBJECTDIR}/_ext/1690398464/usb_descriptors.o ${OBJECTDIR}/main.o ${OBJECTDIR}/1wire.o ${OBJECTDIR}/delay.o ${OBJECTDIR}/LCD_44780.o ${OBJECTDIR}/one-wire.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

# Path to java used to run MPLAB X when this makefile was created
MP_JAVA_PATH="C:\Program Files\Java\jre6/bin/"
OS_CURRENT="$(shell uname -s)"
############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
MP_CC="C:\mcc18\bin\mcc18.exe"
# MP_BC is not defined
MP_AS="C:\mcc18\bin\..\mpasm\MPASMWIN.exe"
MP_LD="C:\mcc18\bin\mplink.exe"
MP_AR="C:\mcc18\bin\mplib.exe"
DEP_GEN=${MP_JAVA_PATH}java -jar "C:/Program Files (x86)/Microchip/MPLABX/mplab_ide/mplab_ide/modules/../../bin/extractobjectdependencies.jar" 
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps
MP_CC_DIR="C:\mcc18\bin"
# MP_BC_DIR is not defined
MP_AS_DIR="C:\mcc18\bin\..\mpasm"
MP_LD_DIR="C:\mcc18\bin"
MP_AR_DIR="C:\mcc18\bin"
# MP_BC_DIR is not defined

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Pic-usb450.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4550
MP_PROCESSOR_OPTION_LD=18f4550
MP_LINKER_DEBUG_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1362431922/usb_function_hid.o: C:/Microchip\ Solutions\ v2011-12-05/Microchip/USB/HID\ Device\ Driver/usb_function_hid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1362431922 
	@${RM} ${OBJECTDIR}/_ext/1362431922/usb_function_hid.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1362431922/usb_function_hid.o   "C:/Microchip Solutions v2011-12-05/Microchip/USB/HID Device Driver/usb_function_hid.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1362431922/usb_function_hid.o 
	
${OBJECTDIR}/_ext/209253324/usb_device.o: C:/Microchip\ Solutions\ v2011-12-05/Microchip/USB/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/209253324 
	@${RM} ${OBJECTDIR}/_ext/209253324/usb_device.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/209253324/usb_device.o   "C:/Microchip Solutions v2011-12-05/Microchip/USB/usb_device.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/209253324/usb_device.o 
	
${OBJECTDIR}/_ext/1690398464/usb_descriptors.o: C:/Microchip\ Solutions\ v2011-12-05/USB/Device\ -\ HID\ -\ Custom\ Demos/Firmware/usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1690398464 
	@${RM} ${OBJECTDIR}/_ext/1690398464/usb_descriptors.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1690398464/usb_descriptors.o   "C:/Microchip Solutions v2011-12-05/USB/Device - HID - Custom Demos/Firmware/usb_descriptors.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1690398464/usb_descriptors.o 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	
${OBJECTDIR}/1wire.o: 1wire.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/1wire.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/1wire.o   1wire.c 
	@${DEP_GEN} -d ${OBJECTDIR}/1wire.o 
	
${OBJECTDIR}/delay.o: delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/delay.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/delay.o   delay.c 
	@${DEP_GEN} -d ${OBJECTDIR}/delay.o 
	
${OBJECTDIR}/LCD_44780.o: LCD_44780.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_44780.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_44780.o   LCD_44780.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_44780.o 
	
${OBJECTDIR}/one-wire.o: one-wire.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/one-wire.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PICKIT2=1 -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/one-wire.o   one-wire.c 
	@${DEP_GEN} -d ${OBJECTDIR}/one-wire.o 
	
else
${OBJECTDIR}/_ext/1362431922/usb_function_hid.o: C:/Microchip\ Solutions\ v2011-12-05/Microchip/USB/HID\ Device\ Driver/usb_function_hid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1362431922 
	@${RM} ${OBJECTDIR}/_ext/1362431922/usb_function_hid.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1362431922/usb_function_hid.o   "C:/Microchip Solutions v2011-12-05/Microchip/USB/HID Device Driver/usb_function_hid.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1362431922/usb_function_hid.o 
	
${OBJECTDIR}/_ext/209253324/usb_device.o: C:/Microchip\ Solutions\ v2011-12-05/Microchip/USB/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/209253324 
	@${RM} ${OBJECTDIR}/_ext/209253324/usb_device.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/209253324/usb_device.o   "C:/Microchip Solutions v2011-12-05/Microchip/USB/usb_device.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/209253324/usb_device.o 
	
${OBJECTDIR}/_ext/1690398464/usb_descriptors.o: C:/Microchip\ Solutions\ v2011-12-05/USB/Device\ -\ HID\ -\ Custom\ Demos/Firmware/usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1690398464 
	@${RM} ${OBJECTDIR}/_ext/1690398464/usb_descriptors.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1690398464/usb_descriptors.o   "C:/Microchip Solutions v2011-12-05/USB/Device - HID - Custom Demos/Firmware/usb_descriptors.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1690398464/usb_descriptors.o 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	
${OBJECTDIR}/1wire.o: 1wire.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/1wire.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/1wire.o   1wire.c 
	@${DEP_GEN} -d ${OBJECTDIR}/1wire.o 
	
${OBJECTDIR}/delay.o: delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/delay.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/delay.o   delay.c 
	@${DEP_GEN} -d ${OBJECTDIR}/delay.o 
	
${OBJECTDIR}/LCD_44780.o: LCD_44780.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/LCD_44780.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/LCD_44780.o   LCD_44780.c 
	@${DEP_GEN} -d ${OBJECTDIR}/LCD_44780.o 
	
${OBJECTDIR}/one-wire.o: one-wire.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/one-wire.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -I"C:/Microchip Solutions v2011-12-05/Microchip/Include" -I".." -I"../../../../../MCC18/h" -I"C:/Microchip Solutions v2011-12-05/Microchip/Include/USB" -I"C:/Microchip Solutions v2011-12-05/Microchip/USB" -I"C:/MCC18/h" -pa=4  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/one-wire.o   one-wire.c 
	@${DEP_GEN} -d ${OBJECTDIR}/one-wire.o 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Pic-usb450.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "C:\Microchip Solutions v2011-12-05\USB\Device - HID - Custom Demos\Firmware\rm18f4550 - HID Bootload.lkr"   -w -x -u_DEBUG -m"$(BINDIR_)$(TARGETBASE).map" -w -l"../../../../../mcc18/lib"  -z__MPLAB_BUILD=1  -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PICKIT2=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/Pic-usb450.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}  LIB-L\LaurTec_c18_libraries\LCD_44780\LCD_44780.lib LIB-L\LaurTec_c18_libraries\delay\delay.lib 
else
dist/${CND_CONF}/${IMAGE_TYPE}/Pic-usb450.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "C:\Microchip Solutions v2011-12-05\USB\Device - HID - Custom Demos\Firmware\rm18f4550 - HID Bootload.lkr"   -w  -m"$(BINDIR_)$(TARGETBASE).map" -w -l"../../../../../mcc18/lib"  -z__MPLAB_BUILD=1  -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/Pic-usb450.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}  LIB-L\LaurTec_c18_libraries\LCD_44780\LCD_44780.lib LIB-L\LaurTec_c18_libraries\delay\delay.lib 
endif


# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
