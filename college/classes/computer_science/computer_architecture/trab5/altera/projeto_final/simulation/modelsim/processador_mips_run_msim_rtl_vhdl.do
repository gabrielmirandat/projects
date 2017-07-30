transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {C:/altera/13.0/projeto_final/regbuf.vhd}
vcom -93 -work work {C:/altera/13.0/projeto_final/reg.vhd}
vcom -93 -work work {C:/altera/13.0/projeto_final/mips_pkg.vhd}
vcom -93 -work work {C:/altera/13.0/projeto_final/ulamips.vhd}
vcom -93 -work work {C:/altera/13.0/projeto_final/processador_mips.vhd}
vcom -93 -work work {C:/altera/13.0/projeto_final/mux_4.vhd}
vcom -93 -work work {C:/altera/13.0/projeto_final/mux_3.vhd}
vcom -93 -work work {C:/altera/13.0/projeto_final/mux_2.vhd}
vcom -93 -work work {C:/altera/13.0/projeto_final/mips_mem.vhd}
vcom -93 -work work {C:/altera/13.0/projeto_final/mips_control.vhd}
vcom -93 -work work {C:/altera/13.0/projeto_final/extsgn.vhd}
vcom -93 -work work {C:/altera/13.0/projeto_final/breg.vhd}
vcom -93 -work work {C:/altera/13.0/projeto_final/alu_ctr.vhd}

vcom -93 -work work {C:/altera/13.0/projeto_final/processador_mips_tb.vhd}

vsim -t 1ps -L altera -L lpm -L sgate -L altera_mf -L altera_lnsim -L cycloneii -L rtl_work -L work -voptargs="+acc"  processador_mips_tb

add wave *
view structure
view signals
run 530 ps
