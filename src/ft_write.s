; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: esouhail </var/spool/mail/esouhail>        +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2026/06/03 18:17:02 by esouhail          #+#    #+#              ;
;    Updated: 2026/06/03 19:03:27 by esouhail         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

bits    64
section .text
global  ft_write
extern  __errno_location

;   calling the write syscall
;   1	common	write			sys_write


ft_write:   ; rdi (fd) - rsi (*buf) - rdx (count)
    mov     rax, 1
    syscall
    cmp     rax, 0
    jl      .error
    ret

.error:
    neg     rax
    push    rax

    call    __errno_location wrt ..plt
    
    pop     r8
    mov     dword [rax], r8d
    mov     rax, -1
    ret

