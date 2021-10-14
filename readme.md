# LeetCode 练习日志
## 配置 LeetCode Editor on Clion

1. 安装插件 [LeetCode Editor](https://plugins.jetbrains.com/plugin/12132-leetcode-editor)

2. 配置插件

   ![截屏2021-10-14 下午3.27.41](https://cse2020-dune.oss-cn-shanghai.aliyuncs.com/20211014152841.png)

   上图中配置包括：使用自定义模板、配置文件名模板、配置代码模板

   我自己的配置：

   - Code Filename

     ```
     $!velocityTool.snakeCaseName($!velocityTool.replaceChars(${question.frontendQuestionId}, "剑指 Offer ", "offer"))_${question.titleSlug}
     ```

   - Code Template

     ```
     ${question.content}
     
     ${question.code}
     
     int main() {
         Solution s;
     }
     ```

## Other Tips

- 仓库记录了从202104-202109的LeetCode刷题日志，主要目标是推免机试，所以选择不熟悉的C++语言做题
  
  - 对C++不熟悉，可以参考[北京理工大学ACM冬季培训课程](https://www.bilibili.com/video/BV1pE411E7RV)
  
- 万能头文件`#include "bits/stdc++.h"`在mac系统的CLion上配置如下：

  ![image-20211014152441096](https://cse2020-dune.oss-cn-shanghai.aliyuncs.com/20211014152442.png)

  CMake options:

  ```
  -D CMAKE_CXX_COMPILER=/usr/local/Cellar/gcc/11.1.0_1/bin/g++-11
  ```

- 安装LeetCode Editor后，可能需要做本机调试，需要安装单文件插件

  CLion 单文件调试: 安装`C/C++ Single File Execution`插件

  ![image-20211014152618348](https://cse2020-dune.oss-cn-shanghai.aliyuncs.com/20211014152619.png)

  在`手动新建/leetcode插件下载`的cpp题目文件中，右键Add即可调试

  ![image-20211014152606260](https://cse2020-dune.oss-cn-shanghai.aliyuncs.com/20211014152607.png)

