# use sphinx
https://zhuanlan.zhihu.com/p/27544821

对整个仓库熟悉

    /oneflow-api-cn/docs/source/cn/activation_ops.py 里的中文是哪来的
        
        首先搞懂英文的是哪来的，是动态设置docstring来的，C++的接口需要添加docstring，于是在 'oneflow/python/oneflow/framework/docstr'下设置.py文件对由C++导出的接口设置docstring  https://github.com/Oneflow-Inc/OneTeam/blob/master/tutorial/howto_write_api_docs.md

        通过调用 docreset.reset_docstr，把原有的 __doc__ 替换为中文翻译。__doc__ 是python对象的一个属性

    /oneflow-api-cn/docs/source/autograd.rst 这个rst文件是什么意思，什么作用

        文本写作文件 https://www.jianshu.com/p/1885d5570b37 内置'..xxxx::' 语法为文本替换 

        rst 文件中导出接口 https://github.com/Oneflow-Inc/OneTeam/blob/master/tutorial/howto_write_api_docs.md

        rst 只是目录文件？？？-配置文档结构？？


        rst导出C++接口变成python对象，.py接收这个对象并修改内置__doc__属性

    
     make html 命令，其实就是利用了工具 sphinx-build，将 oneflow 中对象的 docstring 提取出来，生成 HTML 文件。

     make html 时的内部原理如下，即 sphinx 先读取 conf.py，并在其中 import oneflow，然后读取 *.rst 文件，确认要生成哪些 Python 接口的文档，然后提取它们的 docstring，并生成 HTML 文件。

     docreset/__init__.py 删除的global是什么意思

     https://www.bilibili.com/read/cv11923872


**rst文件与.py文件的关系**

- rst 文件中导出C++接口，.py文件接收每个接口然后调用 docreset.reset_docstr，把原有的 __doc__ 替换为中文翻译，（rst导出C++接口变成python对象，.py接收这个对象并修改内置__doc__属性）。
  
- 这里的中文翻译是人工加上的么？
  
**添加.readthedocs.yaml文件的意义?我了解到的是直接在官网链接仓库 同时配置样式就能直接用rtd。.readthedocs.yaml文件里面的内容我明白是官网上的示例**
- `html_theme = 'sphinx_rtd_theme'`
  
**docreset/__init__.py 里删除的东西的含义FLAG_BUILD 与配置.readthedocs.yaml或者将api.cn加入oneflow主仓库有什么关系**