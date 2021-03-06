# 大程序简介

## 选题背景及意义

文本编辑器（或称文字编辑器）是用作编写普通文字的应用软件，它与文档编辑器（或称文字处理器）不同之处在于它并非用作桌面排版（例如文档格式处理）。

在经历了近一年的程序设计专题学习之后，同学们对包括文件、图形等等内容有了较为全面的了解学习。因此在最后的大程序当中，我们的成员们考虑到知识运用的全面性和综合性，对各项大程序的制作内容和所需知识做了详尽的分析考量，最终选择了文本编辑器这一个对各个知识内容都有较为**细致全面的考察**的任务。成员们可以尝试从**系统开发者角度**来考虑问题，调动自身知识经验探寻解决方法。通过本次大程序的制作，成员们自身的编程能力都得到了一定的锻炼，小组合作能力也有了很大的提升。

## 目标要求

本次我们小组的大程序选择的是文本编辑器的制作，希望在实现基础要求的文本编辑器的输入、复制、粘贴、查找替换等功能之外，附加包括定位行列坐标、撤销、光标选择、键盘快捷键、自动换行等多项功能的满足，以此来完成一个**功能全面多样，界面简洁美观**的文本编辑器的产品制作。

此外，希望本次大程序的制作，可以帮助提高成员们各自的编程能力以及信息处理能力；在小组合作的过程当中，通过成员对大程序的共同撰写，提高成员的沟通协作能力，为后期程序设计的相关知识的学习打下更好的基础。

## 需求分析

### 业务需求
本次我们小组完成的文本编辑器是一个功能近似于Windows系统记事本的基础程序，并且可以实现文本编辑器的各项基础功能。因此其主要面向用户在**文字编辑、文本撰写、文本存储**等文字功能方面的需求，方便使用，页面简洁。因此可以用于解决用户在文字相关领域的大部分问题，为他们提供了更加便捷，简单的文本编辑器使用选择。

### 功能需求

1.	**基础文本撰写与删减功能**
在本次大程序所编写的文本编辑器当中，首先实现的是文字的撰写与编辑功能。用户可以通过键盘输入直接进行在程序显示界面内的字符输入以及中英文编写。此外，用户也可以通过键盘进行相关文字的删除添加功能，即文本编辑器的基础功能。

2.	**光标的选择与定位**
在实现了基础的文本撰写以外，Notepad--也实现了光标在文字位置当中的定位与闪动。其实现可以通过鼠标点击界面直接进行定位，或者是通过键盘进行光标移动。与此同时，在文本编辑器界面的左下角会对光标的坐标进行显示定位，帮助用户更好地确定光标位置，进行相关编辑功能的使用。

3.	**文字的选中**
通过对鼠标点击位置的坐标转化，文本编辑器对文字底色进行修改，实现了对用户选中内容的定位展示。此外，也实现了文本内容的全选的菜单实现以及全选键盘快捷键的操作，方便了用户进行相关操作。

4.	**文件的新建、打开与保存**
Notepad--同样也实现了对于文件的基础功能的实现。用户可以通过操作界面左上角的菜单对文件进行新建，并保存在所需位置。此外，也可以打开原有的文件进行编辑，并进行覆盖保存。

5.	**文本的复制、粘贴与剪切**
除了简单的文字增加删除功能以外，小组也同样实现了对文本的复制粘贴功能。用户可以通过对左上角“编辑”菜单的操作对选中文字进行相关操作，也可以直接通过键盘快捷键实现该类功能。
此外，本次文本编辑器的大程序也实现了与Windows系统的剪切板进行交互，意味着文本的复制粘贴内容可以从系统中的剪切板进行读取，将其他文件当中的文字内容拷贝到文本当中；也可以将在文本编辑器当中的内容写入系统的剪切板当中，实现在程序外相关内容的呈现。

6.	**文字的查找与替换**
用户通过程序界面左上角菜单当中的相关按钮，可以实现所需文字的查找与替换功能。查找将从用户光标位置开始查找，每找到一处就对其进行选中操作，若选择替换功能则在选中后进行替换；在进行“查找下一步”操作之后，若查找到的字符位置坐标不在当前界面的显示范围以内，页面会自动跳转到查找文字所在位置进行显示。在查找到达文本末端后，会返回文本开头继续进行查找，直到查找到最初光标所在位置，实现文本的遍历查找。

7.	**文本字体段落相关设置**
这是Notepad--的对于提高用户使用观感的附加功能，通过菜单当中的“设置”操作，可以实现对文本中文字体的修改，也可以修改字体的大小与颜色。此外，用户也可以对段落的行间距以及界面背景颜色进行修改。同时，在设置界面的下方，也有实例文本的设置范例展示，来方便用户对文本进行模拟修改。

8.	**文本的撤销与重做功能（拓展功能）**
文本编辑器同样也实现了文本的撤销与重做的功能，用户可以通过快捷键的操作，对上一次字符与字符串增加与删减操作进行撤销或者重做，光标自动定位至上一次操作位置。

9.	**相关内容的介绍与帮助**
用户可以通过文本编辑器进行键盘快捷键功能的查找帮助。同时，在菜单当中也有呈现关于Notepad--的开发以及实现。

### 数据需求
Notepad--不需要输入输出数据，但由于libgraphics库的限制，对读取的文件格式及编码有着较高的要求，即要求输入数据为GB2312编码形式的文本文件。

### 性能需求

Notepad--应该要满足对极限测试文件的打开、编辑与储存。由于储存模块的上限为unsigned int的最大值，因此针对2G以上的文件会给予用户温馨提示。

- 对于存有 10,000\*10,000（不含回车）（行列）方阵的测试文件，100,020,000 字节，约 95.3MB，耗时约 3 秒打开，打开后占用内存为 125MB 左右，可以正常编辑，但较为卡顿（越接近行末越卡）。
- 对于存有 3\*100,000,000（不含回车）（行列）的矩阵进行读取，286 MB (300,000,006 字节)，耗时约 8 秒打开，打开后占用内存为 1000MB 左右。约 8 秒保存。可以正常编辑，但非常卡顿。
- 对于存有 100,000,000\*2（不含回车）（行列）的矩阵进行读取，381 MB (400,000,000 字节)，耗时约 12 秒打开，打开后占用内存约为 3000MB。约 5 秒保存。可以流畅编辑。- 
- 对于存有 32768\*32768（不含回车）（行列）的矩阵进行读取，1.00 GB (1,073,807,360 字节)，耗时约 22 秒打开，打开后占用内存 1200MB 左右。约 17 秒保存。可以正常编辑，但较为卡顿（越接近行末越卡）。
- 对于存有 65536\*32768（含回车）（行列）的矩阵进行读取，2.00 GB (2,147,483,648 字节)，耗时约 40 秒打开，打开后占用内存 2000MB 左右。约 34 秒保存。可以正常编辑，但较为卡顿（越接近行末越卡）。
- 对于存有 32768\*65536（含回车）（行列）的矩阵进行读取，2.00 GB (2,147,483,648 字节)，耗时约 40 秒打开，打开后占用内存 2000MB 左右。约 34 秒保存。可以正常编辑，但较为卡顿（越接近行末越卡）。

总的来说，为了对非等宽字体进行支持，在行方向的性能折损较大。列数（行方向）越多、越靠近行末越卡。在打开和保存的速度上，与文件大小成正相关。在内存消耗上，同级别的文件行数越多占用内存越大。这也是类似二维数组的储存结构特性导致的。
