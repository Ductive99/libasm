; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: esouhail <ductive99.github.io>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2026/06/02 16:39:40 by esouhail          #+#    #+#              ;
;    Updated: 2026/06/03 09:15:53 by esouhail         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

bits 64
section .text
global ft_strcmp

ft_strcmp:
    xor     rcx, rcx
.loop:
    movzx   eax, byte [rdi+rcx]
    movzx   edx, byte [rsi+rcx]
    cmp     eax, edx
    jne     .done
    test    eax, eax
    jz      .done
    inc     rcx
    jmp     .loop
.done:
    sub     eax, edx
    ret

