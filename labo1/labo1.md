# Développement - Labo 1

- Inspectez l’aide de GCC (--help) et tentez d’identifier des options permettant d’obtenir les différents états intermédiaires de votre programme (cfr cours théorique). Utilisez ces options sur votre fichier ”hello.c” et observez les fichiers obtenus. Est-ce du texte, du binaire? Esc-ce un exécutable?

    - Sans option, gcc crée un fichier "a.out". Il s'agit de notre fichier executable (ELF 64-bit LSB pie **executable**) :

        ```
        [user@arch labo1]$ ls -l
        -rwxr-xr-x 1 user wheel  16608 23 sep 09:05 hello
        -rw-r--r-- 1 user wheel     67 23 sep 09:05 hello.c
        ```
        ```
        [user@arch labo1]$ file hello
        hello: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=8f68d69ba5617141c9eca7af6986974b2d013d24, for GNU/Linux 3.2.0, not stripped
        ```
    - Liste des options permettant d’obtenir les différents états intermédiaires du programme :

        ```bash
        [user@arch labo1]$ gcc --help
        ...
        -E       Pré-traitement seul ; ne pas compiler, assembler ou éditer les liens.
        -S       Compilation seule ; ne pas assembler ou éditer les liens.
        -c       Compiler et assembler, mais ne pas éditer les liens.
        ...
        ```
        - L'option -E permet d'effectuer les pré-traitement. Il s'agit de l'étape durant laquelle le compilateur s'occupe de traiter les directives préprocesseur. C'est notament à ce moment là qu'est importé le code relatif aux "includes" et "define". Pour plus d'infos sur le language préprocesseur, voir [wiki](https://fr.wikibooks.org/wiki/Programmation_C/Pr%C3%A9processeur).

        - L'option -S permet de compiler le programme sans en éditer les liens. De cette compilation résulte un fichier .s reconnu comme étant un fichier source assembleur :

            ```bash
            [user@arch labo1]$ ls -l
            -rwxr-xr-x 1 user wheel  16608 23 sep 09:05 hello
            -rw-r--r-- 1 user wheel     67 23 sep 09:05 hello.c
            -rw-r--r-- 1 user wheel    455 23 sep 09:24 hello.s
            ```
            ```
            [user@arch labo1]$ file hello.s
            hello.s: assembler source, ASCII text
            ```
            ```
            [user@arch labo1]$ cat hello.s
                .file	"hello.c"
                .text
                .section	.rodata
            .LC0:
                .string	"Hello world!"
                .text
                .globl	main
                .type	main, @function
            main:
            .LFB0:
                .cfi_startproc
                pushq	%rbp
                .cfi_def_cfa_offset 16
                .cfi_offset 6, -16
                movq	%rsp, %rbp
                .cfi_def_cfa_register 6
                leaq	.LC0(%rip), %rdi
                movl	$0, %eax
                call	printf@PLT
                movl	$0, %eax
                popq	%rbp
                .cfi_def_cfa 7, 8
                ret
                .cfi_endproc
            .LFE0:
                .size	main, .-main
                .ident	"GCC: (GNU) 10.2.0"
                .section	.note.GNU-stack,"",@progbits

            ```
    - L'option -c permet de réaliser la compilation et l'assemblage mais pas l'éditage de lien. Nous obtenons un fichier objet ".o"  (ELF 64-bits LSB **relocatable**) :

        ```
        [user@arch labo1]$ ls -l
        total 232
        -rwxr-xr-x 1 user wheel  16608 23 sep 09:05 hello
        -rw-r--r-- 1 user wheel     67 23 sep 09:05 hello.c
        -rw-r--r-- 1 user wheel   1528 23 sep 09:30 hello.o
        -rw-r--r-- 1 user wheel    455 23 sep 09:24 hello.s
        ```
        ```
        [user@arch labo1]$ file hello.o
        hello.o: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), not stripped
        ```
- Écrivez un programme utilisant une variable sans l’avoir déclarée au préalable, dans un printf par exemple. Quelle erreur obtenez-vous du compilateur? :

    ```
    [user@arch labo1]$ gcc test.c
    test.c: Dans la fonction « main »:
    test.c:7:13: erreur: « c » non déclaré (première utilisation dans cette fonction)
        7 |     a + b = c;
          |             ^
    test.c:7:13: note: chaque identificateur non déclaré est rapporté une seule fois pour chaque fonction dans laquelle il apparaît

    ```
- Idem mais avec une variable qui a été déclarée mais pas initialisée. Obtenez-vous une erreur du compilateur? Testez avec des variables de différents types. Que pouvez-vous en conclure? :

    - Aucune erreur n'est levée par le compilateur. Pour un int, char, long et short la variable est initialisée à 0. Pour un float, la valeur choisie est un nombre entier signé aléatoire. J'en conclus qu'il est important d'initialiser sa variable après l'avoir déclarée.
- Écrivez un programme qui tente de déclarer une variable qui existe déjà mais avec un autre type. Quelle erreur obtenez-vous du compilateur?

    ```
    [user@arch labo1]$ gcc test.c && ./a.out
    test1.c: Dans la fonction « main »:
    test1.c:8:11: erreur: types conflictuels pour « a »
        8 |     float a = 23.4;
          |           ^
    test1.c:7:9: note: la définition précédente de « a » était ici
        7 |     int a = 10;
    ```
- Écrivez un programme qui assigne des valeurs à des variables dont le type ne correspond pas, comme un réel à un entier ou un caractère à un réel (testez différentes combinaisons), puis qui affiche ces variables avec printf. Obtenez-vous une erreur du compilateur? Quelles valeurs s’affichent? Que concluez-vous?

    ```
    [user@arch labo1]$ gcc test.c && ./a.out
    test.c: Dans la fonction « main »:
    test.c:6:13: attention: le débordement dans la conversion de « int » vers « char » change la valeur de « 1213812327 » en « 103 » [-Woverflow]
        6 |    char a = 1213812327;
          |             ^~~~~~~~~~
    ```
    - Aucune erreur n'est levée, simplement un warning. Le compilateur nous informe que la valeur de la variable à été modifiée à cause d'un overflow.
- Les différents types possèdent une valeur représentable maximale. Vérifiez à l’aide d’un programme ce qu’il se passe lorsque celle-ci est dépassée. Pa**texte en gras**r exemple ajoutez 1 à une variable char initialisée à 127 et affichez ensuite la valeur de cette variable.

    ```
    [user@arch labo1]$ gcc test.c && ./a.out
    127
    -128
    ```
- Testez le programme ci-dessus. Qu’observez-vous? :

    - Si on tente d'afficher une variable de type int en l'invocant comme un float, le résultat du print est 0.

        ```bash
        [user@arch labo1]$ gcc test.c && ./a.out
        0.000000
        1.000000
        ```
- Testez le principe inverse, l’affichage d’un entier mais où on fournit un réel (avec et dans casting. Qu'observez-vous? :

    - Si on tente d'afficher une varible de type float en l'invocant comme un int, le résultat obtenue est un nombre signé aléatoire.

        ```bash
        [user@arch labo1]$ gcc test.c && ./a.out
        -1761679336
        1
        [user@arch labo1]$ gcc test.c && ./a.out
        1626085688
        1
        ```
- Écrivez un programme qui déclare un entier et y assigne le casting d’une valeur r´eelle non-entière, puis qui affiche cet entier. Que constatez-vous? Quel lien pouvez-vous faire avec l'exercice précedant? :

    - Je constate que lors du cast d'un float en int, la partie décimal du nombre est tronquée.
- Écrivez un programme qui tente de modifier la valeur d’une variable constante. Quelle erreur obtenez-vous du compilateur? :

    ```bash
    [user@arch labo1]$ gcc test.c && ./a.out
    test.c: Dans la fonction « main »:
    test.c:6:6: erreur: affectation de la variable « i » en lecture seule
        6 |     i=10;
          |
    ```
- Écrivez une programme qui affiche la valeur d’une constante symbolique PI (3.14) et un autre qui affiche cette même valeur mais avec une variable constante. Comparez le code de ces deux programmes après les avoir fournis uniquement au préprocessor (voir
    point 2). Que remarquez-vous?
    - Le define PI n'est plus présent dans le code une fois précompilé. Le mot "PI" est cependant remplacé par 3.14.

- Au vu de l’exercice précédent, pensez-vous que le programme suivant, qui utilise des constantes symboliques, peut fonctionner? Réfléchissez bien avant de le tester et tentez de justifier votre réponse ! :

	- Oui cela fonctionne.


- Testez le comportement des différents opérateurs arithmétiques avec différentes combinaisons de types, par exemple une division d’entiers, l’addition d’un entier et d’un réel, d’un entier et d’un caractère ...  Qu’observez-vous?
	- Le compilateur retourne un warning nous indiquant qu'une variable à été transformée sans transtypage.
	- Lors de l'exécution du programme, nous obtenons une erreur de segmentation.

- Écrivez  un  programme  qui  affiche  la  valeur  de  la  division  réelle  de  deux  variables entières.  Que devez-vous utiliser pour y arriver?

	- Nous devons utiliser le type casting. Il est en effet nécessaire de modifier le type de notre dividende avant de diviser celui-ci.

- Au vu de l’exercice précédent, quel problème voyez-vous à l’utilisation de la notation rapide? Testez ce problème avec un programme.

	- Avec cette notation rapode, il serait impossible de caster notre dividende. Il est donc impossible d'obtenir un résultat cohérent.

- A sa création, le langage C ne gérait pas les types booléens.  D’après vous, quel type renvoient donc les opérateurs booléens?  Testez votre réponse avec un programme.
	- Il s'agit du type "integer" qui est souvent utiliser pour représenter les booléens.
		- 0 == False
		- 1 == True
	- Les opérateurs de comparaison ( > , == , etc.) sont définis pour retourner un int.
