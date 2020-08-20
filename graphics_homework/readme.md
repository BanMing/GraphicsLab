
## 课程地址
https://sites.cs.ucsb.edu/~lingqi/teaching/games101.html

## mac 环境配置：

http://games-cn.org/forums/topic/macbook-shiyongvscodewanchengzuoye0dehuanjingpeizhi/

    brew install engine

vscode在mac下的智能提示和报错问题，
在.vscode文件夹下创建c_cpp_properties.json

    {
        "configurations": [
            {
                "name": "Mac",
                "includePath": [
                    "/usr/local/include",
                    "${workspaceFolder}/**"
                ],
                "defines": [],
                "macFrameworkPath": [],
                "compilerPath": "/usr/local/bin/gcc-9",
                "intelliSenseMode": "gcc-x64"
            }
        ],
        "version": 4
    }