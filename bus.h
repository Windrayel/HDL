#ifndef _BUS_H
#define _BUS_H

#include "systemc.h"
#include "structures.h"

SC_MODULE(Bus)
{
	sc_in<bool>  clk_i;
	sc_port<sc_signal_in_if<message>, cpu_number, SC_ALL_BOUND> master_port_in;
	sc_port<sc_signal_out_if<message>, cpu_number, SC_ALL_BOUND> master_port_out;
	sc_in<message> slave_port_in;
	sc_out<message> slave_port_out;

	Bus(sc_module_name nm);
};


#endif