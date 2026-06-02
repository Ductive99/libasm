; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: esouhail <esouhail@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2026/06/02 16:01:17 by esouhail          #+#    #+#              ;
;    Updated: 2026/06/02 16:05:28 by esouhail         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

bits 64 
section .text
global ft_strlen

ft_strlen:
    xor rax, rax            ; set counter to 0
.loop:
    cmp byte [rdi+rax], 0   ; rdi is 1st argument + rax offset
    je  .done
    inc rax
    jmp .loop
.done:
    ret                     ; returns the value in rax
