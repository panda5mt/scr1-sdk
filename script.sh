#!/bin/bash -eu
#
##
##	Compile SCR1 C code on GCC and 
##	build SCR1 Soft-core CPU logic Quartus Prime.
##	(need WSL on Windows 10)
##	written by Lynxeyed(http://lynxeyed.hatenablog.com/)
##
## PATH to riscv-gcc
export PATH=$PATH:/opt/riscv/bin
C_PATH=/opt/riscv/bin

## setting up quartus/sopc folder
QUARTUS_ROOTDIR=/mnt/c/intelFPGA_lite/19.1/quartus/bin64
SOPC_ROOTDIR=/mnt/c/intelFPGA_lite/19.1/quartus/sopc_builder/bin

## setting up target name
DESIGN_NAME=cy10lp
SW_DESIGN_NAME=de10lite_scr1

## target folder (Project folder)
RISCV_PROJ_DIR=/mnt/c/RISCV/Syntacore/scr1-sdk
RISCV_WINDIR=`wslpath -w ${RISCV_PROJ_DIR}`

## Folder for generate *.SVF
## qsys folder (to generate "qsys-custom-memory-map".h)  
SVFDIR=${RISCV_PROJ_DIR}/fpga/cy10lp/scr1/output
SVFDIRW=`wslpath -w ${SVFDIR}`
QSYSDIR=${RISCV_PROJ_DIR}/fpga/cy10lp/scr1/qsys
QSYSDIRW=`wslpath -w ${QSYSDIR}`
SWDIR=${RISCV_PROJ_DIR}/sw/sc-bl
SWDIRW=`wslpath -w ${SWDIR}`


## compile by riscv-gcc
cd ${SWDIR}
make deep_clean
make CROSS_COMPILE=riscv64-unknown-elf- PLATFORM=${SW_DESIGN_NAME}

## build by Quartus Prime(19.1 or later)
cd ${RISCV_PROJ_DIR}/fpga/cy10lp/scr1
#	${QUARTUS_ROOTDIR}/quartus_sh.exe --flow clean cy10lp
${QUARTUS_ROOTDIR}/quartus_sh.exe --flow compile cy10lp

## generate SVF
cd ${SVFDIR}
${QUARTUS_ROOTDIR}/quartus_cpf.exe -c -n p -q 2MHz -g 3.3 ${SVFDIRW}/${DESIGN_NAME}.sof ${SVFDIRW}/${DESIGN_NAME}.svf

## generate "qsys-custom-memory-map".h
cd ${QSYSDIR}
${SOPC_ROOTDIR}/sopcinfo2swinfo.exe --input=${QSYSDIRW}/${DESIGN_NAME}_qsys.sopcinfo
${SOPC_ROOTDIR}/swinfo2header.exe --swinfo ${QSYSDIRW}/${DESIGN_NAME}_qsys.swinfo --module avl_dmem --single ${SWDIRW}/src/qsys_mem_map.h 


# Copy build *.SVF file to your Raspberry Pi(for example:Pi on 192.168.1.10)
scp -r ${SVFDIR}/${DESIGN_NAME}.svf pi@192.168.1.10:/home/pi
