
ps3:     file format elf64-x86-64


Disassembly of section .init:

00000000004006c8 <_init>:
  4006c8:	48 83 ec 08          	sub    $0x8,%rsp
  4006cc:	48 8b 05 25 09 20 00 	mov    0x200925(%rip),%rax        # 600ff8 <_DYNAMIC+0x1f0>
  4006d3:	48 85 c0             	test   %rax,%rax
  4006d6:	74 05                	je     4006dd <_init+0x15>
  4006d8:	e8 33 00 00 00       	callq  400710 <__gmon_start__@plt>
  4006dd:	48 83 c4 08          	add    $0x8,%rsp
  4006e1:	c3                   	retq   

Disassembly of section .plt:

00000000004006f0 <printf@plt-0x10>:
  4006f0:	ff 35 12 09 20 00    	pushq  0x200912(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  4006f6:	ff 25 14 09 20 00    	jmpq   *0x200914(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  4006fc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400700 <printf@plt>:
  400700:	ff 25 12 09 20 00    	jmpq   *0x200912(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400706:	68 00 00 00 00       	pushq  $0x0
  40070b:	e9 e0 ff ff ff       	jmpq   4006f0 <_init+0x28>

0000000000400710 <__gmon_start__@plt>:
  400710:	ff 25 0a 09 20 00    	jmpq   *0x20090a(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400716:	68 01 00 00 00       	pushq  $0x1
  40071b:	e9 d0 ff ff ff       	jmpq   4006f0 <_init+0x28>

0000000000400720 <__libc_start_main@plt>:
  400720:	ff 25 02 09 20 00    	jmpq   *0x200902(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400726:	68 02 00 00 00       	pushq  $0x2
  40072b:	e9 c0 ff ff ff       	jmpq   4006f0 <_init+0x28>

0000000000400730 <_ZNSsD1Ev@plt>:
  400730:	ff 25 fa 08 20 00    	jmpq   *0x2008fa(%rip)        # 601030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400736:	68 03 00 00 00       	pushq  $0x3
  40073b:	e9 b0 ff ff ff       	jmpq   4006f0 <_init+0x28>

0000000000400740 <_ZNSsC1EPKcRKSaIcE@plt>:
  400740:	ff 25 f2 08 20 00    	jmpq   *0x2008f2(%rip)        # 601038 <_GLOBAL_OFFSET_TABLE_+0x38>
  400746:	68 04 00 00 00       	pushq  $0x4
  40074b:	e9 a0 ff ff ff       	jmpq   4006f0 <_init+0x28>

0000000000400750 <_ZNSaIcED1Ev@plt>:
  400750:	ff 25 ea 08 20 00    	jmpq   *0x2008ea(%rip)        # 601040 <_GLOBAL_OFFSET_TABLE_+0x40>
  400756:	68 05 00 00 00       	pushq  $0x5
  40075b:	e9 90 ff ff ff       	jmpq   4006f0 <_init+0x28>

0000000000400760 <_ZNSaIcEC1Ev@plt>:
  400760:	ff 25 e2 08 20 00    	jmpq   *0x2008e2(%rip)        # 601048 <_GLOBAL_OFFSET_TABLE_+0x48>
  400766:	68 06 00 00 00       	pushq  $0x6
  40076b:	e9 80 ff ff ff       	jmpq   4006f0 <_init+0x28>

0000000000400770 <__gxx_personality_v0@plt>:
  400770:	ff 25 da 08 20 00    	jmpq   *0x2008da(%rip)        # 601050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400776:	68 07 00 00 00       	pushq  $0x7
  40077b:	e9 70 ff ff ff       	jmpq   4006f0 <_init+0x28>

0000000000400780 <_Unwind_Resume@plt>:
  400780:	ff 25 d2 08 20 00    	jmpq   *0x2008d2(%rip)        # 601058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400786:	68 08 00 00 00       	pushq  $0x8
  40078b:	e9 60 ff ff ff       	jmpq   4006f0 <_init+0x28>

Disassembly of section .text:

0000000000400790 <_start>:
  400790:	31 ed                	xor    %ebp,%ebp
  400792:	49 89 d1             	mov    %rdx,%r9
  400795:	5e                   	pop    %rsi
  400796:	48 89 e2             	mov    %rsp,%rdx
  400799:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40079d:	50                   	push   %rax
  40079e:	54                   	push   %rsp
  40079f:	49 c7 c0 90 09 40 00 	mov    $0x400990,%r8
  4007a6:	48 c7 c1 20 09 40 00 	mov    $0x400920,%rcx
  4007ad:	48 c7 c7 7d 08 40 00 	mov    $0x40087d,%rdi
  4007b4:	e8 67 ff ff ff       	callq  400720 <__libc_start_main@plt>
  4007b9:	f4                   	hlt    
  4007ba:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004007c0 <deregister_tm_clones>:
  4007c0:	b8 77 10 60 00       	mov    $0x601077,%eax
  4007c5:	55                   	push   %rbp
  4007c6:	48 2d 70 10 60 00    	sub    $0x601070,%rax
  4007cc:	48 83 f8 0e          	cmp    $0xe,%rax
  4007d0:	48 89 e5             	mov    %rsp,%rbp
  4007d3:	77 02                	ja     4007d7 <deregister_tm_clones+0x17>
  4007d5:	5d                   	pop    %rbp
  4007d6:	c3                   	retq   
  4007d7:	b8 00 00 00 00       	mov    $0x0,%eax
  4007dc:	48 85 c0             	test   %rax,%rax
  4007df:	74 f4                	je     4007d5 <deregister_tm_clones+0x15>
  4007e1:	5d                   	pop    %rbp
  4007e2:	bf 70 10 60 00       	mov    $0x601070,%edi
  4007e7:	ff e0                	jmpq   *%rax
  4007e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004007f0 <register_tm_clones>:
  4007f0:	b8 70 10 60 00       	mov    $0x601070,%eax
  4007f5:	55                   	push   %rbp
  4007f6:	48 2d 70 10 60 00    	sub    $0x601070,%rax
  4007fc:	48 c1 f8 03          	sar    $0x3,%rax
  400800:	48 89 e5             	mov    %rsp,%rbp
  400803:	48 89 c2             	mov    %rax,%rdx
  400806:	48 c1 ea 3f          	shr    $0x3f,%rdx
  40080a:	48 01 d0             	add    %rdx,%rax
  40080d:	48 d1 f8             	sar    %rax
  400810:	75 02                	jne    400814 <register_tm_clones+0x24>
  400812:	5d                   	pop    %rbp
  400813:	c3                   	retq   
  400814:	ba 00 00 00 00       	mov    $0x0,%edx
  400819:	48 85 d2             	test   %rdx,%rdx
  40081c:	74 f4                	je     400812 <register_tm_clones+0x22>
  40081e:	5d                   	pop    %rbp
  40081f:	48 89 c6             	mov    %rax,%rsi
  400822:	bf 70 10 60 00       	mov    $0x601070,%edi
  400827:	ff e2                	jmpq   *%rdx
  400829:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400830 <__do_global_dtors_aux>:
  400830:	80 3d 39 08 20 00 00 	cmpb   $0x0,0x200839(%rip)        # 601070 <__TMC_END__>
  400837:	75 11                	jne    40084a <__do_global_dtors_aux+0x1a>
  400839:	55                   	push   %rbp
  40083a:	48 89 e5             	mov    %rsp,%rbp
  40083d:	e8 7e ff ff ff       	callq  4007c0 <deregister_tm_clones>
  400842:	5d                   	pop    %rbp
  400843:	c6 05 26 08 20 00 01 	movb   $0x1,0x200826(%rip)        # 601070 <__TMC_END__>
  40084a:	f3 c3                	repz retq 
  40084c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400850 <frame_dummy>:
  400850:	48 83 3d a8 05 20 00 	cmpq   $0x0,0x2005a8(%rip)        # 600e00 <__JCR_END__>
  400857:	00 
  400858:	74 1e                	je     400878 <frame_dummy+0x28>
  40085a:	b8 00 00 00 00       	mov    $0x0,%eax
  40085f:	48 85 c0             	test   %rax,%rax
  400862:	74 14                	je     400878 <frame_dummy+0x28>
  400864:	55                   	push   %rbp
  400865:	bf 00 0e 60 00       	mov    $0x600e00,%edi
  40086a:	48 89 e5             	mov    %rsp,%rbp
  40086d:	ff d0                	callq  *%rax
  40086f:	5d                   	pop    %rbp
  400870:	e9 7b ff ff ff       	jmpq   4007f0 <register_tm_clones>
  400875:	0f 1f 00             	nopl   (%rax)
  400878:	e9 73 ff ff ff       	jmpq   4007f0 <register_tm_clones>

000000000040087d <main>:
  40087d:	55                   	push   %rbp
  40087e:	48 89 e5             	mov    %rsp,%rbp
  400881:	53                   	push   %rbx
  400882:	48 83 ec 28          	sub    $0x28,%rsp
  400886:	48 8d 45 df          	lea    -0x21(%rbp),%rax
  40088a:	48 89 c7             	mov    %rax,%rdi
  40088d:	e8 ce fe ff ff       	callq  400760 <_ZNSaIcEC1Ev@plt>
  400892:	48 8d 55 df          	lea    -0x21(%rbp),%rdx
  400896:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  40089a:	be a8 09 40 00       	mov    $0x4009a8,%esi
  40089f:	48 89 c7             	mov    %rax,%rdi
  4008a2:	e8 99 fe ff ff       	callq  400740 <_ZNSsC1EPKcRKSaIcE@plt>
  4008a7:	48 8d 45 df          	lea    -0x21(%rbp),%rax
  4008ab:	48 89 c7             	mov    %rax,%rdi
  4008ae:	e8 9d fe ff ff       	callq  400750 <_ZNSaIcED1Ev@plt>
  4008b3:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4008b7:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  4008bb:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4008bf:	48 89 c6             	mov    %rax,%rsi
  4008c2:	bf b5 09 40 00       	mov    $0x4009b5,%edi
  4008c7:	b8 00 00 00 00       	mov    $0x0,%eax
  4008cc:	e8 2f fe ff ff       	callq  400700 <printf@plt>
  4008d1:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4008d5:	48 89 c7             	mov    %rax,%rdi
  4008d8:	e8 53 fe ff ff       	callq  400730 <_ZNSsD1Ev@plt>
  4008dd:	b8 00 00 00 00       	mov    $0x0,%eax
  4008e2:	eb 34                	jmp    400918 <main+0x9b>
  4008e4:	48 89 c3             	mov    %rax,%rbx
  4008e7:	48 8d 45 df          	lea    -0x21(%rbp),%rax
  4008eb:	48 89 c7             	mov    %rax,%rdi
  4008ee:	e8 5d fe ff ff       	callq  400750 <_ZNSaIcED1Ev@plt>
  4008f3:	48 89 d8             	mov    %rbx,%rax
  4008f6:	48 89 c7             	mov    %rax,%rdi
  4008f9:	e8 82 fe ff ff       	callq  400780 <_Unwind_Resume@plt>
  4008fe:	48 89 c3             	mov    %rax,%rbx
  400901:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  400905:	48 89 c7             	mov    %rax,%rdi
  400908:	e8 23 fe ff ff       	callq  400730 <_ZNSsD1Ev@plt>
  40090d:	48 89 d8             	mov    %rbx,%rax
  400910:	48 89 c7             	mov    %rax,%rdi
  400913:	e8 68 fe ff ff       	callq  400780 <_Unwind_Resume@plt>
  400918:	48 83 c4 28          	add    $0x28,%rsp
  40091c:	5b                   	pop    %rbx
  40091d:	5d                   	pop    %rbp
  40091e:	c3                   	retq   
  40091f:	90                   	nop

0000000000400920 <__libc_csu_init>:
  400920:	41 57                	push   %r15
  400922:	41 89 ff             	mov    %edi,%r15d
  400925:	41 56                	push   %r14
  400927:	49 89 f6             	mov    %rsi,%r14
  40092a:	41 55                	push   %r13
  40092c:	49 89 d5             	mov    %rdx,%r13
  40092f:	41 54                	push   %r12
  400931:	4c 8d 25 b8 04 20 00 	lea    0x2004b8(%rip),%r12        # 600df0 <__frame_dummy_init_array_entry>
  400938:	55                   	push   %rbp
  400939:	48 8d 2d b8 04 20 00 	lea    0x2004b8(%rip),%rbp        # 600df8 <__init_array_end>
  400940:	53                   	push   %rbx
  400941:	4c 29 e5             	sub    %r12,%rbp
  400944:	31 db                	xor    %ebx,%ebx
  400946:	48 c1 fd 03          	sar    $0x3,%rbp
  40094a:	48 83 ec 08          	sub    $0x8,%rsp
  40094e:	e8 75 fd ff ff       	callq  4006c8 <_init>
  400953:	48 85 ed             	test   %rbp,%rbp
  400956:	74 1e                	je     400976 <__libc_csu_init+0x56>
  400958:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40095f:	00 
  400960:	4c 89 ea             	mov    %r13,%rdx
  400963:	4c 89 f6             	mov    %r14,%rsi
  400966:	44 89 ff             	mov    %r15d,%edi
  400969:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40096d:	48 83 c3 01          	add    $0x1,%rbx
  400971:	48 39 eb             	cmp    %rbp,%rbx
  400974:	75 ea                	jne    400960 <__libc_csu_init+0x40>
  400976:	48 83 c4 08          	add    $0x8,%rsp
  40097a:	5b                   	pop    %rbx
  40097b:	5d                   	pop    %rbp
  40097c:	41 5c                	pop    %r12
  40097e:	41 5d                	pop    %r13
  400980:	41 5e                	pop    %r14
  400982:	41 5f                	pop    %r15
  400984:	c3                   	retq   
  400985:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  40098c:	00 00 00 00 

0000000000400990 <__libc_csu_fini>:
  400990:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000400994 <_fini>:
  400994:	48 83 ec 08          	sub    $0x8,%rsp
  400998:	48 83 c4 08          	add    $0x8,%rsp
  40099c:	c3                   	retq   
