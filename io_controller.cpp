#include "io_controller.h"

IO_contr::IO_contr(sc_module_name nm)
	:sc_module(nm),
	clk_i("clk_i"),
	addr_bo("addr_bo"),
	data_bo("data_bo"),
	wr_o("wr_o"),
	rd_o("rd_o") 
{
	input = {	0, 0, 0, 0, 0, 0, 1,
				0, 0, 0, 1, 0, 0, 0,
				0, 0, 1, 0, 1, 0, 0,
				0, 1, 0, 0, 0, 1, 0,
				1, 0, 0, 0, 0, 0, 1,
				1, 1, 1, 1, 1, 1, 1,
				0, 0, 0, 0, 0, 0, 0 };

	output = { 0, 0, 0 };

	SC_THREAD(write_image);
}

IO_contr::~IO_contr() {

}

void IO_contr::bus_write(int addr, double data) {
	wait();
	addr_bo.write(addr);
	data_bo.write(data);
	wr_o.write(1);

	wait();
	wr_o.write(0);
}

void IO_contr::write_image() {
	for (int i = 0; i < 49; i++) {
		bus_write(i, input[i]);
	}
}
