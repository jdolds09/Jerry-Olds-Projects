/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2011 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE 
 *
 *   for full copyright notice and license terms. 
 *
 */
#include "unctrl.h"

char *_unctrl[0400] = { "^@",
                        "^A",
                        "^B",
                        "^C",
                        "^D",
                        "^E",
                        "^F",
                        "^G",
                        "^H",
                        "^I",
                        "^J",
                        "^K",
                        "^L",
                        "^M",
                        "^N",
                        "^O",
                        "^P",
                        "^Q",
                        "^R",
                        "^S",
                        "^T",
                        "^U",
                        "^V",
                        "^W",
                        "^X",
                        "^Y",
                        "^Z",
                        "^[",
                        "^\\",
                        "^]",
                        "^^",
                        "^_",
                        " ",
                        "!",
                        "\"",
                        "#",
                        "$",
                        "%",
                        "&",
                        "'",
                        "(",
                        ")",
                        "*",
                        "+",
                        ",",
                        "-",
                        ".",
                        "/",
                        "0",
                        "1",
                        "2",
                        "3",
                        "4",
                        "5",
                        "6",
                        "7",
                        "8",
                        "9",
                        ":",
                        ";",
                        "<",
                        "=",
                        ">",
                        "?",
                        "@",
                        "A",
                        "B",
                        "C",
                        "D",
                        "E",
                        "F",
                        "G",
                        "H",
                        "I",
                        "J",
                        "K",
                        "L",
                        "M",
                        "N",
                        "O",
                        "P",
                        "Q",
                        "R",
                        "S",
                        "T",
                        "U",
                        "V",
                        "W",
                        "X",
                        "Y",
                        "Z",
                        "[",
                        "\\",
                        "]",
                        "^",
                        "_",
                        "`",
                        "a",
                        "b",
                        "c",
                        "d",
                        "e",
                        "f",
                        "g",
                        "h",
                        "i",
                        "j",
                        "k",
                        "l",
                        "m",
                        "n",
                        "o",
                        "p",
                        "q",
                        "r",
                        "s",
                        "t",
                        "u",
                        "v",
                        "w",
                        "x",
                        "y",
                        "z",
                        "{"/*}*/,
                        "|",
                        /*{*/"}",
                        "~",
                        "^?",
                        "|^@",
                        "|^A",
                        "|^B",
                        "|^C",
                        "|^D",
                        "|^E",
                        "|^F",
                        "|^G",
                        "|^H",
                        "|^I",
                        "|^J",
                        "|^K",
                        "|^L",
                        "|^M",
                        "|^N",
                        "|^O",
                        "|^P",
                        "|^Q",
                        "|^R",
                        "|^S",
                        "|^T",
                        "|^U",
                        "|^V",
                        "|^W",
                        "|^X",
                        "|^Y",
                        "|^Z",
                        "|^[",
                        "|^\\",
                        "|^]",
                        "|^^",
                        "|^_",
                        "| ",
                        "|!",
                        "|\"",
                        "|#",
                        "|$",
                        "|%",
                        "|&",
                        "|'",
                        "|(",
                        "|)",
                        "|*",
                        "|+",
                        "|,",
                        "|-",
                        "|.",
                        "|/",
                        "|0",
                        "|1",
                        "|2",
                        "|3",
                        "|4",
                        "|5",
                        "|6",
                        "|7",
                        "|8",
                        "|9",
                        "|:",
                        "|;",
                        "|<",
                        "|=",
                        "|>",
                        "|?",
                        "|@",
                        "|A",
                        "|B",
                        "|C",
                        "|D",
                        "|E",
                        "|F",
                        "|G",
                        "|H",
                        "|I",
                        "|J",
                        "|K",
                        "|L",
                        "|M",
                        "|N",
                        "|O",
                        "|P",
                        "|Q",
                        "|R",
                        "|S",
                        "|T",
                        "|U",
                        "|V",
                        "|W",
                        "|X",
                        "|Y",
                        "|Z",
                        "|[",
                        "|\\",
                        "|]",
                        "|^",
                        "|_",
                        "|`",
                        "|a",
                        "|b",
                        "|c",
                        "|d",
                        "|e",
                        "|f",
                        "|g",
                        "|h",
                        "|i",
                        "|j",
                        "|k",
                        "|l",
                        "|m",
                        "|n",
                        "|o",
                        "|p",
                        "|q",
                        "|r",
                        "|s",
                        "|t",
                        "|u",
                        "|v",
                        "|w",
                        "|x",
                        "|y",
                        "|z",
                        "|{"/*}*/,
                        "||",
                        /*{*/"|}",
                        "|~",
                        "|^?" };

char *_Unctrl[0400] = { "^@",
                        "^A",
                        "^B",
                        "^C",
                        "^D",
                        "^E",
                        "^F",
                        "^G",
                        "^H",
                        "^I",
                        "^J",
                        "^K",
                        "^L",
                        "^M",
                        "^N",
                        "^O",
                        "^P",
                        "^Q",
                        "^R",
                        "^S",
                        "^T",
                        "^U",
                        "^V",
                        "^W",
                        "^X",
                        "^Y",
                        "^Z",
                        "^[",
                        "^\\",
                        "^]",
                        "^^",
                        "^_",
                        "sp",
                        "!",
                        "\"",
                        "#",
                        "$",
                        "%",
                        "&",
                        "'",
                        "(",
                        ")",
                        "*",
                        "+",
                        ",",
                        "-",
                        ".",
                        "/",
                        "0",
                        "1",
                        "2",
                        "3",
                        "4",
                        "5",
                        "6",
                        "7",
                        "8",
                        "9",
                        ":",
                        ";",
                        "<",
                        "=",
                        ">",
                        "?",
                        "@",
                        "A",
                        "B",
                        "C",
                        "D",
                        "E",
                        "F",
                        "G",
                        "H",
                        "I",
                        "J",
                        "K",
                        "L",
                        "M",
                        "N",
                        "O",
                        "P",
                        "Q",
                        "R",
                        "S",
                        "T",
                        "U",
                        "V",
                        "W",
                        "X",
                        "Y",
                        "Z",
                        "[",
                        "\\",
                        "]",
                        "^",
                        "_",
                        "`",
                        "a",
                        "b",
                        "c",
                        "d",
                        "e",
                        "f",
                        "g",
                        "h",
                        "i",
                        "j",
                        "k",
                        "l",
                        "m",
                        "n",
                        "o",
                        "p",
                        "q",
                        "r",
                        "s",
                        "t",
                        "u",
                        "v",
                        "w",
                        "x",
                        "y",
                        "z",
                        "{"/*}*/,
                        "|",
                        /*{*/"}",
                        "~",
                        "^?",
                        "|^@",
                        "|^A",
                        "|^B",
                        "|^C",
                        "|^D",
                        "|^E",
                        "|^F",
                        "|^G",
                        "|^H",
                        "|^I",
                        "|^J",
                        "|^K",
                        "|^L",
                        "|^M",
                        "|^N",
                        "|^O",
                        "|^P",
                        "|^Q",
                        "|^R",
                        "|^S",
                        "|^T",
                        "|^U",
                        "|^V",
                        "|^W",
                        "|^X",
                        "|^Y",
                        "|^Z",
                        "|^[",
                        "|^\\",
                        "|^]",
                        "|^^",
                        "|^_",
                        "|sp",
                        "|!",
                        "|\"",
                        "|#",
                        "|$",
                        "|%",
                        "|&",
                        "|'",
                        "|(",
                        "|)",
                        "|*",
                        "|+",
                        "|,",
                        "|-",
                        "|.",
                        "|/",
                        "|0",
                        "|1",
                        "|2",
                        "|3",
                        "|4",
                        "|5",
                        "|6",
                        "|7",
                        "|8",
                        "|9",
                        "|:",
                        "|;",
                        "|<",
                        "|=",
                        "|>",
                        "|?",
                        "|@",
                        "|A",
                        "|B",
                        "|C",
                        "|D",
                        "|E",
                        "|F",
                        "|G",
                        "|H",
                        "|I",
                        "|J",
                        "|K",
                        "|L",
                        "|M",
                        "|N",
                        "|O",
                        "|P",
                        "|Q",
                        "|R",
                        "|S",
                        "|T",
                        "|U",
                        "|V",
                        "|W",
                        "|X",
                        "|Y",
                        "|Z",
                        "|[",
                        "|\\",
                        "|]",
                        "|^",
                        "|_",
                        "|`",
                        "|a",
                        "|b",
                        "|c",
                        "|d",
                        "|e",
                        "|f",
                        "|g",
                        "|h",
                        "|i",
                        "|j",
                        "|k",
                        "|l",
                        "|m",
                        "|n",
                        "|o",
                        "|p",
                        "|q",
                        "|r",
                        "|s",
                        "|t",
                        "|u",
                        "|v",
                        "|w",
                        "|x",
                        "|y",
                        "|z",
                        "|{"/*}*/,
                        "||",
                        /*{*/"|}",
                        "|~",
                        "|^?" };
