; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: esouhail <ductive99.github.io>             +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2026/06/04 10:38:45 by esouhail          #+#    #+#              ;
;    Updated: 2026/06/04 15:29:04 by esouhail         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

bits    64
global  ft_strdup
extern  ft_strlen
extern  ft_strcpy
extern  malloc

section .text

ft_strdup:
    ; 1. Get length of the original string
    push    rdi
    call    ft_strlen
    
    ; 2. Allocate memory
    inc     rax
    mov     rdi, rax
    call    malloc
    
    ; 3. Check for malloc failure
    cmp     rax, 0
    je      .error
    
    ; 4. Copy the string
    mov     rdi, rax    ; rdi (Argument 1 for ft_strcpy: dest)
    pop     rsi         ; rsi (Argument 2: src)
    call    ft_strcpy   ; ft_strcpy returns the dest pointer in rax, 
    ret

.error:
    pop     rdi
    ret
