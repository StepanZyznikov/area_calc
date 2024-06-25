extern printf

section .data
    k dd 0  
    
section .text
global _f1, _f1p, _f2, _f2p, _f3, _f3p

_f1:
    enter 0, 0
    finit 
    fld qword[ebp+8]
    fld qword[ebp+8]
    fmul
    mov dword[k], 7
    fimul dword[k]
    fld qword[ebp+8]
    mov dword[k], 19
    fimul dword[k]
    fsub 
    mov dword[k], 54
    fiadd dword[k]
    mov dword[k], 20
    fidiv dword[k]
    leave
    ret
    
_f1p:
    enter 0, 0
    finit 
    fld qword[ebp+8]
    mov dword[k], 14
    fimul dword[k]
    mov dword[k], 19
    fild dword[k]
    fsub 
    mov dword[k], 20
    fidiv dword[k]
    leave
    ret
    
_f2:
    enter 0, 0
    finit 
    fld qword[ebp+8]
    mov dword[k], 3
    fimul dword[k]
    mov dword[k], 1
    fiadd dword[k]
    leave
    ret
    
_f2p:
    enter 0, 0
    finit 
    mov dword[k], 3
    fild dword[k]
    leave
    ret
    
_f3:
    enter 0, 0
    finit 
    mov dword[k], 1
    fild dword[k]
    fld qword[ebp+8]
    mov dword[k], 2
    fiadd dword[k]
    fdiv
    leave
    ret
    
_f3p:
    enter 0, 0
    finit 
    mov dword[k], -1
    fild dword[k]
    fld qword[ebp+8]
    mov dword[k], 2
    fiadd dword[k]
    fld qword[ebp+8]
    mov dword[k], 2
    fiadd dword[k]
    fmul
    fdiv
    leave
    ret