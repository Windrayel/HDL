#include "cpu.h"
#include "mem.h"
#include "io_controller.h"
#include "bus.h"
#include "structures.h"

int sc_main(int argc, char* argv[])
{

    std::vector<CPU> cpu_cores(cpu_number);
    Mem memory("memory");
    IO_contr io("io_controller");

    sc_clock clk("clk", sc_time(10, SC_NS));
    sc_signal<int> addr;
    sc_signal<double> data_io_bo;
    sc_signal<double> data_io_bi;
    sc_signal<bool> wr;
    sc_signal<bool> rd;
    std::vector<sc_signal<message>> master_port_in(cpu_number);
    std::vector<sc_signal<message>> master_port_out(cpu_number);

    for (int i = 0; i < cpu_number; i++) {
        cpu_cores[i].unit_num = i;
        cpu_cores[i].clk_i(clk);
        cpu_cores[i].data_bi(master_port_out[i]);
        cpu_cores[i].data_bo(master_port_in[i]);
        cpu_cores[i].wr_o(wr);
        cpu_cores[i].rd_o(rd);
    }

    memory.clk_i(clk);
    memory.addr_bi(addr);
    memory.data_bi(data_io_bo);
    memory.data_bo(data_io_bi);
    memory.wr_i(wr);
    memory.rd_i(rd);

    io.clk_i(clk);
    io.addr_bo(addr);
    io.data_bo(data_io_bi);
    io.wr_o(wr);
    io.rd_o(rd);

    sc_trace_file* wf = sc_create_vcd_trace_file("wave");
    sc_trace(wf, clk, "clk");
    sc_trace(wf, addr, "addr_bo");
    sc_trace(wf, data_io_bi, "data_bi");
    sc_trace(wf, data_io_bo, "data_bo");
    //for (int i = 0; i < cpu_number; i++) {
    //    sc_trace(wf, master_port_in[i], "master_port_in " + std::to_string(i));
    //    sc_trace(wf, master_port_out[i], "master_port_out " + std::to_string(i));
    //}

    sc_trace(wf, wr, "wr");
    sc_trace(wf, rd, "rd");

    sc_start();


    sc_close_vcd_trace_file(wf);

    return(0);

}
