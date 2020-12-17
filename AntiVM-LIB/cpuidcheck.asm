OPTION DOTNAME
.data
.code
public cpuidcheck
    cpuidcheck PROC
            ; function prologue 
            mov    [RSP + 8], RCX
            push   R15
            push   R14
            push   R13
            sub    RSP, 10h
            
            ; function start 
            mov     r9, rcx             ; one
            mov     r10, rdx            ; two 
	        xor     rax, rax            ; clean eax for usage with cpuid
            mov     rax, 40000000h
            cpuid                       
            ; Compare the return values of ebx, ecx, edx to the proper string annotation
            cmp     rbx, r9            
            jne     WrongType            
            cmp     rcx, r10    
            jne     WrongType
            cmp     rdx, r8
            jne     WrongType
            ; If I made it here, its the correct string value saved 
            mov     eax, 1
        
        WrongType:
            add      RSP, 10h
            pop      R13
            pop      R14
            pop      R15
            ret
    cpuidcheck ENDP
END
