## turing-machine-implementation-c

### Source machine
```sh
tape 111100000111_
current_state qp
accept_state qf
qp,1,qp,1,>
qp,0,qi,0,>
qi,1,qi,1,>
qi,0,qp,0,>
qp,_,qf,_,<
```

### Run
```sh
make && ./main
```


