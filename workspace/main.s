	.file	"main.cpp"
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
.lcomm _ZStL8__ioinit,1,1
	.section	.text$_ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_,"x"
	.linkonce discard
	.globl	_ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_
	.def	_ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_
_ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_:
.LFB1464:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN6PersonC2ESs,"x"
	.linkonce discard
	.align 2
	.globl	_ZN6PersonC2ESs
	.def	_ZN6PersonC2ESs;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN6PersonC2ESs
_ZN6PersonC2ESs:
.LFB1465:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	leaq	16+_ZTV6Person(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	_ZN6Person11m_idCounterE(%rip), %rax
	addq	$1, %rax
	movq	%rax, _ZN6Person11m_idCounterE(%rip)
	movq	_ZN6Person11m_idCounterE(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rcx
	call	_ZNSsC1EOSs
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN6PersonC1ESs,"x"
	.linkonce discard
	.align 2
	.globl	_ZN6PersonC1ESs
	.def	_ZN6PersonC1ESs;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN6PersonC1ESs
_ZN6PersonC1ESs:
.LFB1466:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	leaq	16+_ZTV6Person(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	_ZN6Person11m_idCounterE(%rip), %rax
	addq	$1, %rax
	movq	%rax, _ZN6Person11m_idCounterE(%rip)
	movq	_ZN6Person11m_idCounterE(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_
	movq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rcx
	call	_ZNSsC1EOSs
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN6PersonD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN6PersonD2Ev
	.def	_ZN6PersonD2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN6PersonD2Ev
_ZN6PersonD2Ev:
.LFB1468:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTV6Person(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rcx
	call	_ZNSsD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN6PersonD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN6PersonD1Ev
	.def	_ZN6PersonD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN6PersonD1Ev
_ZN6PersonD1Ev:
.LFB1469:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTV6Person(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rcx
	call	_ZNSsD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN6PersonD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN6PersonD0Ev
	.def	_ZN6PersonD0Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN6PersonD0Ev
_ZN6PersonD0Ev:
.LFB1470:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rcx
	call	_ZN6PersonD1Ev
	movl	$24, %edx
	movq	16(%rbp), %rcx
	call	_ZdlPvm
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNK6Person5PrintEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZNK6Person5PrintEv
	.def	_ZNK6Person5PrintEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNK6Person5PrintEv
_ZNK6Person5PrintEv:
.LFB1474:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN6Person11m_idCounterE
	.bss
	.align 8
_ZN6Person11m_idCounterE:
	.space 8
	.text
	.globl	_Z5PrintRK6Person
	.def	_Z5PrintRK6Person;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5PrintRK6Person
_Z5PrintRK6Person:
.LFB1475:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	16(%rbp), %rcx
	call	*%rax
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN3ManC1ESs,"x"
	.linkonce discard
	.align 2
	.globl	_ZN3ManC1ESs
	.def	_ZN3ManC1ESs;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3ManC1ESs
_ZN3ManC1ESs:
.LFB1478:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZSt4moveIRSsEONSt16remove_referenceIT_E4typeEOS2_
	movq	%rax, %rdx
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSsC1EOSs
	movq	16(%rbp), %rax
	leaq	-8(%rbp), %rdx
	movq	%rax, %rcx
	call	_ZN6PersonC2ESs
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSsD1Ev
	leaq	16+_ZTV3Man(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movl	$0, 24(%rax)
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN3ManD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN3ManD1Ev
	.def	_ZN3ManD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3ManD1Ev
_ZN3ManD1Ev:
.LFB1481:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTV3Man(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN6PersonD2Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN3ManD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN3ManD0Ev
	.def	_ZN3ManD0Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN3ManD0Ev
_ZN3ManD0Ev:
.LFB1482:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rcx
	call	_ZN3ManD1Ev
	movl	$32, %edx
	movq	16(%rbp), %rcx
	call	_ZdlPvm
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZNK3Man5PrintEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZNK3Man5PrintEv
	.def	_ZNK3Man5PrintEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNK3Man5PrintEv
_ZNK3Man5PrintEv:
.LFB1483:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.text
	.globl	_Z5PrintRK3Man
	.def	_Z5PrintRK3Man;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5PrintRK3Man
_Z5PrintRK3Man:
.LFB1484:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	16(%rbp), %rcx
	call	*%rax
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Alexey\0"
.LC1:
	.ascii "Sergey\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1485:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$136, %rsp
	.seh_stackalloc	136
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	leaq	-17(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSaIcEC1Ev
	leaq	-17(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %r8
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rcx
.LEHB0:
	call	_ZNSsC1EPKcRKSaIcE
.LEHE0:
	leaq	-32(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN3ManC1ESs
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSsD1Ev
	leaq	-17(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSaIcED1Ev
	leaq	-1(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSaIcEC1Ev
	leaq	-1(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %r8
	leaq	.LC1(%rip), %rdx
	movq	%rax, %rcx
.LEHB1:
	call	_ZNSsC1EPKcRKSaIcE
.LEHE1:
	leaq	-16(%rbp), %rdx
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN6PersonC1ESs
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSsD1Ev
	leaq	-1(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSaIcED1Ev
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN6PersonD1Ev
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN3ManD1Ev
	movl	$0, %eax
	jmp	.L21
.L19:
	movq	%rax, %rbx
	leaq	-17(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSaIcED1Ev
	movq	%rbx, %rax
	movq	%rax, %rcx
.LEHB2:
	call	_Unwind_Resume
.L20:
	movq	%rax, %rbx
	leaq	-1(%rbp), %rax
	movq	%rax, %rcx
	call	_ZNSaIcED1Ev
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN3ManD1Ev
	movq	%rbx, %rax
	movq	%rax, %rcx
	call	_Unwind_Resume
.LEHE2:
.L21:
	addq	$136, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA1485:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1485-.LLSDACSB1485
.LLSDACSB1485:
	.uleb128 .LEHB0-.LFB1485
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L19-.LFB1485
	.uleb128 0
	.uleb128 .LEHB1-.LFB1485
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L20-.LFB1485
	.uleb128 0
	.uleb128 .LEHB2-.LFB1485
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE1485:
	.text
	.seh_endproc
	.globl	_ZTV3Man
	.section	.rdata$_ZTV3Man,"dr"
	.linkonce same_size
	.align 8
_ZTV3Man:
	.quad	0
	.quad	_ZTI3Man
	.quad	_ZN3ManD1Ev
	.quad	_ZN3ManD0Ev
	.quad	_ZNK3Man5PrintEv
	.globl	_ZTV6Person
	.section	.rdata$_ZTV6Person,"dr"
	.linkonce same_size
	.align 8
_ZTV6Person:
	.quad	0
	.quad	_ZTI6Person
	.quad	_ZN6PersonD1Ev
	.quad	_ZN6PersonD0Ev
	.quad	_ZNK6Person5PrintEv
	.globl	_ZTI3Man
	.section	.rdata$_ZTI3Man,"dr"
	.linkonce same_size
	.align 8
_ZTI3Man:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS3Man
	.quad	_ZTI6Person
	.globl	_ZTS3Man
	.section	.rdata$_ZTS3Man,"dr"
	.linkonce same_size
_ZTS3Man:
	.ascii "3Man\0"
	.globl	_ZTI6Person
	.section	.rdata$_ZTI6Person,"dr"
	.linkonce same_size
	.align 8
_ZTI6Person:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS6Person
	.globl	_ZTS6Person
	.section	.rdata$_ZTS6Person,"dr"
	.linkonce same_size
	.align 8
_ZTS6Person:
	.ascii "6Person\0"
	.text
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB1868:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L24
	cmpl	$65535, 24(%rbp)
	jne	.L24
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	movq	.refptr.__dso_handle(%rip), %r8
	leaq	_ZStL8__ioinit(%rip), %rdx
	movq	.refptr._ZNSt8ios_base4InitD1Ev(%rip), %rcx
	call	__cxa_atexit
.L24:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I__ZN6Person11m_idCounterE;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__ZN6Person11m_idCounterE
_GLOBAL__sub_I__ZN6Person11m_idCounterE:
.LFB1869:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__ZN6Person11m_idCounterE
	.ident	"GCC: (GNU) 6.4.0"
	.def	_ZNSsC1EOSs;	.scl	2;	.type	32;	.endef
	.def	_ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvm;	.scl	2;	.type	32;	.endef
	.def	_ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSsC1EPKcRKSaIcE;	.scl	2;	.type	32;	.endef
	.def	_ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	__cxa_atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZNSt8ios_base4InitD1Ev, "dr"
	.globl	.refptr._ZNSt8ios_base4InitD1Ev
	.linkonce	discard
.refptr._ZNSt8ios_base4InitD1Ev:
	.quad	_ZNSt8ios_base4InitD1Ev
	.section	.rdata$.refptr.__dso_handle, "dr"
	.globl	.refptr.__dso_handle
	.linkonce	discard
.refptr.__dso_handle:
	.quad	__dso_handle
