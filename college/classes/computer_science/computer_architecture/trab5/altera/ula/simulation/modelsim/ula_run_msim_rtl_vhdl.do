transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {C:/altera/13.0/ula/ulaMIPS.vhdl}

vcom -93 -work work {C:/altera/13.0/ula/ulaMIPS_tb.vhdl}

vsim -t 1ps -L altera -L lpm -L sgate -L altera_mf -L altera_lnsim -L cycloneii -L rtl_work -L work -voptargs="+acc"  ulaMIPS_tb

add wave *
view structure
view signals
run 60 ps
