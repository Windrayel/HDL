#pragma once
const int cpu_number = 3;

struct message
{
	int unit_number; // 0 for io_contr, others for cpu
	double neuron;
	double weight;
	bool is_end;
	bool is_req;
};