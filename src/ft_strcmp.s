; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: esouhail <ductive99.github.io>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2026/06/02 16:39:40 by esouhail          #+#    #+#              ;
;    Updated: 2026/06/02 18:40:04 by esouhail         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

bits 64
section .text
global ft_strcmp

ft_strcmp:
    xor     rax, rax
.loop:
    mov     r8b, byte [rdi+rax]
    mov     r9b, byte [rsi+rax]
    cmp     r8b, r9b
    jne     .done
    cmp     r8b, 0
    je      .done
    inc     rax
    jmp     .loop
.done:
    sub     r8, r9
    mov     rax, r8
    ret

