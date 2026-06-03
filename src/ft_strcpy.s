; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: esouhail <ductive99.github.io>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2026/06/03 12:17:23 by esouhail          #+#    #+#              ;
;    Updated: 2026/06/03 14:18:43 by esouhail         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

bits    64
section .text
global  ft_strcpy


ft_strcpy:
    xor     rcx, rcx
.loop:
    mov     al, byte [rsi+rcx]
    mov     byte [rdi+rcx], al
    test    al, al
    jz      .done
    inc     rcx
    jmp     .loop
.done:
    mov     rax, rdi
    ret
