#!/bin/bash
# /mnt/c/intelFPGA_lite/19.1/quartus/bin64/quartus_sh.exe --flow compile Cy10LP_Eval
# wslpath -w $PWD
# quartus_cpf -c -n p -q 2MHz -g 3.3 $(DESIGN_NAME ).sof $(DESIGN_NAME).svf
export PATH=$PATH:/opt/riscv/bin
C_PATH=/opt/riscv/bin
QUARTUS_ROOTDIR=/mnt/c/intelFPGA_lite/19.1/quartus/bin64
SOPC_ROOTDIR=/mnt/c/intelFPGA_lite/19.1/quartus/sopc_builder/bin
DESIGN_NAME=de10lite
SW_DESIGN_NAME=de10lite_scr1

RISCV_PROJ_DIR=/mnt/c/RISCV/Syntacore/scr1-sdk
RISCV_WINDIR=`wslpath -w ${RISCV_PROJ_DIR}`

SVFDIR=${RISCV_PROJ_DIR}/fpga/de10lite/scr1/output
SVFDIRW=`wslpath -w ${SVFDIR}`
QSYSDIR=${RISCV_PROJ_DIR}/fpga/de10lite/scr1/qsys
QSYSDIRW=`wslpath -w ${QSYSDIR}`
SWDIR=${RISCV_PROJ_DIR}/sw/riscv_test
SWDIRW=`wslpath -w ${SWDIR}`

cd ${SWDIR}
make deep_clean
make CROSS_COMPILE=riscv64-unknown-elf- PLATFORM=${SW_DESIGN_NAME}


cd ${RISCV_PROJ_DIR}/fpga/de10lite/scr1
#	${QUARTUS_ROOTDIR}/quartus_sh.exe --flow clean de10lite
${QUARTUS_ROOTDIR}/quartus_sh.exe --flow compile de10lite
cd ${SVFDIR}
${QUARTUS_ROOTDIR}/quartus_cpf.exe -c -n p -q 2MHz -g 3.3 ${SVFDIRW}/${DESIGN_NAME}.sof ${SVFDIRW}/${DESIGN_NAME}.svf
cd ${QSYSDIR}

${SOPC_ROOTDIR}/sopcinfo2swinfo.exe --input=${QSYSDIRW}/${DESIGN_NAME}_qsys.sopcinfo
${SOPC_ROOTDIR}/swinfo2header.exe --swinfo ${QSYSDIRW}/${DESIGN_NAME}_qsys.swinfo --module avl_dmem --single ${SWDIRW}/qsys_mem_map.h 

scp -r ${SVFDIR}/${DESIGN_NAME}.svf lynx@192.168.10.106:/home/lynx
