; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: esouhail <ductive99.github.io>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2026/06/03 19:04:37 by esouhail          #+#    #+#              ;
;    Updated: 2026/06/03 19:06:55 by esouhail         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

bits    64
section .text
global  ft_read
extern  __errno_location

ft_read:
    mov     rax, 0
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
