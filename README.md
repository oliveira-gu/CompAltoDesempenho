# MPI Study Exercises

Small C programs developed to review and practice **Message Passing Interface (MPI)** concepts for the High Performance Computing (HPC) course.

The exercises focus on programming for cluster environments using **Open MPI**, with progressively more complex examples involving process initialization, process identification, point-to-point communication, and data distribution.

---

## 📚 Objectives

This repository is intended as a practical review of the following MPI concepts:

- MPI initialization and finalization
- MPI processes and process IDs (`rank`)
- Number of processes (`size`)
- `MPI_COMM_WORLD`
- Point-to-point communication
- `MPI_Send()`
- `MPI_Recv()`
- Master/child process organization
- Distribution of data among processes
- Compilation with `mpicc`
- Execution with `mpirun`
- Basic Makefile usage
- Git and `.gitignore` organization

The exercises are intentionally small so that each concept can be analyzed independently.

---

## 🛠️ Requirements

The examples were developed for a Linux environment using Open MPI.

Install Open MPI on Ubuntu with:

```bash
sudo apt update
sudo apt install openmpi-bin libopenmpi-dev
