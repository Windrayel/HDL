#include "bus.h"

Bus::Bus(sc_module_name nm)
    :sc_module(nm),
    clk_i("clk_i"),
    master_port_in("master_port_in"),
    master_port_out("master_port_out"),
    slave_port_in("slave_port_in"),
    slave_port_out("slave_port_out")
{

}
