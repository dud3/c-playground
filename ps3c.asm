
ps3c:     file format elf64-x86-64


Disassembly of section .init:

0000000000400440 <_init>:
  400440:	48 83 ec 08          	sub    $0x8,%rsp
  400444:	48 8b 05 ad 0b 20 00 	mov    0x200bad(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d0>
  40044b:	48 85 c0             	test   %rax,%rax
  40044e:	74 05                	je     400455 <_init+0x15>
  400450:	e8 4b 00 00 00       	callq  4004a0 <__gmon_start__@plt>
  400455:	48 83 c4 08          	add    $0x8,%rsp
  400459:	c3                   	retq   

Disassembly of section .plt:

0000000000400460 <__stack_chk_fail@plt-0x10>:
  400460:	ff 35 a2 0b 20 00    	pushq  0x200ba2(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400466:	ff 25 a4 0b 20 00    	jmpq   *0x200ba4(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40046c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400470 <__stack_chk_fail@plt>:
  400470:	ff 25 a2 0b 20 00    	jmpq   *0x200ba2(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400476:	68 00 00 00 00       	pushq  $0x0
  40047b:	e9 e0 ff ff ff       	jmpq   400460 <_init+0x20>

0000000000400480 <printf@plt>:
  400480:	ff 25 9a 0b 20 00    	jmpq   *0x200b9a(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400486:	68 01 00 00 00       	pushq  $0x1
  40048b:	e9 d0 ff ff ff       	jmpq   400460 <_init+0x20>

0000000000400490 <__libc_start_main@plt>:
  400490:	ff 25 92 0b 20 00    	jmpq   *0x200b92(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400496:	68 02 00 00 00       	pushq  $0x2
  40049b:	e9 c0 ff ff ff       	jmpq   400460 <_init+0x20>

00000000004004a0 <__gmon_start__@plt>:
  4004a0:	ff 25 8a 0b 20 00    	jmpq   *0x200b8a(%rip)        # 601030 <_GLOBAL_OFFSET_TABLE_+0x30>
  4004a6:	68 03 00 00 00       	pushq  $0x3
  4004ab:	e9 b0 ff ff ff       	jmpq   400460 <_init+0x20>

Disassembly of section .text:

00000000004004b0 <_start>:
  4004b0:	31 ed                	xor    %ebp,%ebp
  4004b2:	49 89 d1             	mov    %rdx,%r9
  4004b5:	5e                   	pop    %rsi
  4004b6:	48 89 e2             	mov    %rsp,%rdx
  4004b9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4004bd:	50                   	push   %rax
  4004be:	54                   	push   %rsp
  4004bf:	49 c7 c0 90 06 40 00 	mov    $0x400690,%r8
  4004c6:	48 c7 c1 20 06 40 00 	mov    $0x400620,%rcx
  4004cd:	48 c7 c7 9d 05 40 00 	mov    $0x40059d,%rdi
  4004d4:	e8 b7 ff ff ff       	callq  400490 <__libc_start_main@plt>
  4004d9:	f4                   	hlt    
  4004da:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004004e0 <deregister_tm_clones>:
  4004e0:	b8 4f 10 60 00       	mov    $0x60104f,%eax
  4004e5:	55                   	push   %rbp
  4004e6:	48 2d 48 10 60 00    	sub    $0x601048,%rax
  4004ec:	48 83 f8 0e          	cmp    $0xe,%rax
  4004f0:	48 89 e5             	mov    %rsp,%rbp
  4004f3:	77 02                	ja     4004f7 <deregister_tm_clones+0x17>
  4004f5:	5d                   	pop    %rbp
  4004f6:	c3                   	retq   
  4004f7:	b8 00 00 00 00       	mov    $0x0,%eax
  4004fc:	48 85 c0             	test   %rax,%rax
  4004ff:	74 f4                	je     4004f5 <deregister_tm_clones+0x15>
  400501:	5d                   	pop    %rbp
  400502:	bf 48 10 60 00       	mov    $0x601048,%edi
  400507:	ff e0                	jmpq   *%rax
  400509:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400510 <register_tm_clones>:
  400510:	b8 48 10 60 00       	mov    $0x601048,%eax
  400515:	55                   	push   %rbp
  400516:	48 2d 48 10 60 00    	sub    $0x601048,%rax
  40051c:	48 c1 f8 03          	sar    $0x3,%rax
  400520:	48 89 e5             	mov    %rsp,%rbp
  400523:	48 89 c2             	mov    %rax,%rdx
  400526:	48 c1 ea 3f          	shr    $0x3f,%rdx
  40052a:	48 01 d0             	add    %rdx,%rax
  40052d:	48 d1 f8             	sar    %rax
  400530:	75 02                	jne    400534 <register_tm_clones+0x24>
  400532:	5d                   	pop    %rbp
  400533:	c3                   	retq   
  400534:	ba 00 00 00 00       	mov    $0x0,%edx
  400539:	48 85 d2             	test   %rdx,%rdx
  40053c:	74 f4                	je     400532 <register_tm_clones+0x22>
  40053e:	5d                   	pop    %rbp
  40053f:	48 89 c6             	mov    %rax,%rsi
  400542:	bf 48 10 60 00       	mov    $0x601048,%edi
  400547:	ff e2                	jmpq   *%rdx
  400549:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400550 <__do_global_dtors_aux>:
  400550:	80 3d f1 0a 20 00 00 	cmpb   $0x0,0x200af1(%rip)        # 601048 <__TMC_END__>
  400557:	75 11                	jne    40056a <__do_global_dtors_aux+0x1a>
  400559:	55                   	push   %rbp
  40055a:	48 89 e5             	mov    %rsp,%rbp
  40055d:	e8 7e ff ff ff       	callq  4004e0 <deregister_tm_clones>
  400562:	5d                   	pop    %rbp
  400563:	c6 05 de 0a 20 00 01 	movb   $0x1,0x200ade(%rip)        # 601048 <__TMC_END__>
  40056a:	f3 c3                	repz retq 
  40056c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400570 <frame_dummy>:
  400570:	48 83 3d a8 08 20 00 	cmpq   $0x0,0x2008a8(%rip)        # 600e20 <__JCR_END__>
  400577:	00 
  400578:	74 1e                	je     400598 <frame_dummy+0x28>
  40057a:	b8 00 00 00 00       	mov    $0x0,%eax
  40057f:	48 85 c0             	test   %rax,%rax
  400582:	74 14                	je     400598 <frame_dummy+0x28>
  400584:	55                   	push   %rbp
  400585:	bf 20 0e 60 00       	mov    $0x600e20,%edi
  40058a:	48 89 e5             	mov    %rsp,%rbp
  40058d:	ff d0                	callq  *%rax
  40058f:	5d                   	pop    %rbp
  400590:	e9 7b ff ff ff       	jmpq   400510 <register_tm_clones>
  400595:	0f 1f 00             	nopl   (%rax)
  400598:	e9 73 ff ff ff       	jmpq   400510 <register_tm_clones>

000000000040059d <main>:
  40059d:	55                   	push   %rbp
  40059e:	48 89 e5             	mov    %rsp,%rbp
  4005a1:	48 83 ec 30          	sub    $0x30,%rsp
  4005a5:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4005ac:	00 00 
  4005ae:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  4005b2:	31 c0                	xor    %eax,%eax
  4005b4:	48 b8 48 65 6c 6c 6f 	movabs $0x77202c6f6c6c6548,%rax
  4005bb:	2c 20 77 
  4005be:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
  4005c2:	c7 45 e8 6f 72 64 6c 	movl   $0x6c64726f,-0x18(%rbp)
  4005c9:	c6 45 ec 00          	movb   $0x0,-0x14(%rbp)
  4005cd:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4005d1:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
  4005d5:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4005d9:	48 89 c6             	mov    %rax,%rsi
  4005dc:	bf a4 06 40 00       	mov    $0x4006a4,%edi
  4005e1:	b8 00 00 00 00       	mov    $0x0,%eax
  4005e6:	e8 95 fe ff ff       	callq  400480 <printf@plt>
  4005eb:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  4005ef:	0f b6 00             	movzbl (%rax),%eax
  4005f2:	0f be c0             	movsbl %al,%eax
  4005f5:	89 c6                	mov    %eax,%esi
  4005f7:	bf a8 06 40 00       	mov    $0x4006a8,%edi
  4005fc:	b8 00 00 00 00       	mov    $0x0,%eax
  400601:	e8 7a fe ff ff       	callq  400480 <printf@plt>
  400606:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  40060a:	64 48 33 14 25 28 00 	xor    %fs:0x28,%rdx
  400611:	00 00 
  400613:	74 05                	je     40061a <main+0x7d>
  400615:	e8 56 fe ff ff       	callq  400470 <__stack_chk_fail@plt>
  40061a:	c9                   	leaveq 
  40061b:	c3                   	retq   
  40061c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400620 <__libc_csu_init>:
  400620:	41 57                	push   %r15
  400622:	41 89 ff             	mov    %edi,%r15d
  400625:	41 56                	push   %r14
  400627:	49 89 f6             	mov    %rsi,%r14
  40062a:	41 55                	push   %r13
  40062c:	49 89 d5             	mov    %rdx,%r13
  40062f:	41 54                	push   %r12
  400631:	4c 8d 25 d8 07 20 00 	lea    0x2007d8(%rip),%r12        # 600e10 <__frame_dummy_init_array_entry>
  400638:	55                   	push   %rbp
  400639:	48 8d 2d d8 07 20 00 	lea    0x2007d8(%rip),%rbp        # 600e18 <__init_array_end>
  400640:	53                   	push   %rbx
  400641:	4c 29 e5             	sub    %r12,%rbp
  400644:	31 db                	xor    %ebx,%ebx
  400646:	48 c1 fd 03          	sar    $0x3,%rbp
  40064a:	48 83 ec 08          	sub    $0x8,%rsp
  40064e:	e8 ed fd ff ff       	callq  400440 <_init>
  400653:	48 85 ed             	test   %rbp,%rbp
  400656:	74 1e                	je     400676 <__libc_csu_init+0x56>
  400658:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40065f:	00 
  400660:	4c 89 ea             	mov    %r13,%rdx
  400663:	4c 89 f6             	mov    %r14,%rsi
  400666:	44 89 ff             	mov    %r15d,%edi
  400669:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40066d:	48 83 c3 01          	add    $0x1,%rbx
  400671:	48 39 eb             	cmp    %rbp,%rbx
  400674:	75 ea                	jne    400660 <__libc_csu_init+0x40>
  400676:	48 83 c4 08          	add    $0x8,%rsp
  40067a:	5b                   	pop    %rbx
  40067b:	5d                   	pop    %rbp
  40067c:	41 5c                	pop    %r12
  40067e:	41 5d                	pop    %r13
  400680:	41 5e                	pop    %r14
  400682:	41 5f                	pop    %r15
  400684:	c3                   	retq   
  400685:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  40068c:	00 00 00 00 

0000000000400690 <__libc_csu_fini>:
  400690:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000400694 <_fini>:
  400694:	48 83 ec 08          	sub    $0x8,%rsp
  400698:	48 83 c4 08          	add    $0x8,%rsp
  40069c:	c3                   	retq   
