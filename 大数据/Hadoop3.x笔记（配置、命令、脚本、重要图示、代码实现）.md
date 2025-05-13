## Hadoop 3.x 笔记 

> 作者： Zzay
> 
> 目的： 本文章记录 `hadoop 3.x` 使用过程中常用的配置、命令、脚本、重要图示、实现代码，以方便未来查看使用。

  


## 1. 常用配置 

### 1.1 端口号 

> 以下是`Hadoop 3.x`常用的端口号。

 *  NameNode HTTP UI 端口：9870
 *  NameNode 内部通信端口：8020/9000/9820
 *  Secondary NameNode：9868
 *  YARN 查看执行任务端口（ResourceManager）：8088
 *  历史服务器通信端口（jobHistory）：10020
 *  历史服务器通信WEB端口（jobHistory.webapp）：19888

### 1.2 参数配置 

> 以下是 `Hadoop 3.x` 常用的生产环境参数配置。（root：`$HADOOP_HOME$/etc/hadoop/`）

#### 1.2.1 Hadoop 全局参数 

 *  `core-site.xml`：配置 Hadoop 相关的全局信息
    
     *  指定 NameNode 地址：`fs.defaultFS`
     *  指定 hadoop 数据的存储目录：`hadoop.tmp.dir`
     *  配置 HDFS 网页登录使用的静态用户： `hadoop.http.staticuser.user`
 *  `workers`：工作结点的相关配置信息

#### 1.2.2 HDFS 

 *  `hdfs-default.xml`：HDFS 默认配置信息
    
     *  配置 Secondary NameNode 的Checkpoint间隔时长（默认3600s）：`dfs.namenode.checkpoint.period`
     *  配置 Secondary NameNode 一分钟内可接受的最多操作数（默认100万）：`dfs.namenode.checkpoint.txns`
     *  配置 Secondary NameNode 检查操作数是否到达极限的间隔时长（默认60s）：`dfs.namenode.checkpoint.check.period`
 *  `hdfs-site.xml`：HDFS 相关配置信息
    
     *  配置 NameNode 在Web端的访问URL：`dfs.namenode.http-address`
     *  配置 Secondary NameNode 在Web端的访问URL：`dfs.namenode.secondary.http-address`

#### 1.2.3 MapReduce 

 *  `mapred-site.xml`：MapReduce 相关配置信息

#### 1.2.4 YARN 

 *  `yarn-site.xml`：YARN 相关配置信息
    
     *  指定 MR 走shuffle：`yarn.nodemanager.aux-services`
     *  指定 ResourceManager 的地址：`yarn.resourcemanager.hostname`
     *  配置环境变量的继承：`yarn.nodemanager.env-whitelist`
     *  开启日志聚集功能：`yarn.log-aggregation-enable`
     *  设置日志聚集服务器地址：`yarn.log.server.url`
     *  设置日志保留时间：`yarn.log-aggregation.retain-seconds`
 *  ResourceManager 相关的核心参数：
    
     *  配置调度器（默认容量调度器）：`yarn.resourcemanager.scheduler.class`
     *  ResourceManager 处理调度器请求的线程数量（默认50）：`yarn.resourcemanager.scheduler.client.thread-count`
 *  NodeManager 相关的核心参数：
    
     *  是否让 YARN 自己检测硬件进行配置（默认false）：`yarn.nodemanager.resource.detect-hardware-capabilities`
     *  NodeManager 使用CPU核数（默认8个）：`yarn.nodemanager.resource.cpu-vcores`
     *  是否将虚拟核数当作CPU核数（默认false）：`yarn.nodemanager.resource.count-logical-processors-as-cores`
     *  虚拟核数和物理核数的乘数，例如：4核8线程，该参数就应设为2（默认1.0）： `yarn.nodemanager.resource.pcores-vcores-multiplier`
     *  NodeManager 使用内存（默认8G）：`yarn.nodemanager.resource.memory-mb`
     *  NodeManager 为系统保留多少内存：`yarn.nodemanager.resource.system-reserved-memory-mb`
     *  是否开启物理内存检查限制 container（默认true）：`yarn.nodemanager.pmem-check-enabled`
     *  是否开启虚拟内存检查限制 container（默认true）：`yarn.nodemanager.vmem-check-enabled`
     *  虚拟内存物理内存比例（默认2：1）：`yarn.nodemanager.vmem-pmem-ratio`
 *  Container 相关的核心参数：
    
     *  容器最小内存（默认1G）：`yarn.scheduler.minimum-allocation-mb`
     *  容器最大内存（默认8G）：`yarn.scheduler.maximum-allocation-mb`
     *  容器最小CPU核数（默认1个）：`yarn.scheduler.minimum-allocation-vcores`
     *  容器最大CPU核数（默认4个）：`yarn.scheduler.maximum-allocation-vcores`

  


## 2. 常用命令 

> 以下是`Hadoop 3.x`使用过程中一些常用的命令。

### 2.1 hadoop 全局命令 

 *  启动/停止 Hadoop 集群：
    
    ```java
    $HADOOP_HOME$/sbin/start-dfs.sh
    $HADOOP_HOME$/sbin/start-yarn.sh
    
    $HADOOP_HOME$/sbin/stop-dfs.sh
    $HADOOP_HOME$/sbin/stop-yarn.sh
    ```
 *  启动历史服务器 `historyserver`：
    
    ```java
    $HADOOP_HOME$/bin/mapred --daemon start historyserver
    
    $HADOOP_HOME$/bin/mapred --daemon stop historyserver
    ```

### 2.2 HDFS Shell 命令 

```java
$ hdfs dfs COMMAND
```

#### 2.2.1 基本操作 

 *  `-help`：查询命令细节
    
    ```java
    $ hdfs dfs -help 命令名称
    ```
 *  `-mkdir`：创建文件夹
    
    ```java
    $ hdfs dfs -mkdir 文件夹名称
    ```
 *  `-ls`：显示目录信息
    
    ```java
    $ hdfs dfs -ls 目录地址
    ```
 *  `-cat`：显示文件内容
    
    ```java
    $ hdfs dfs -cat 文件地址
    ```
 *  `-chmod / -chown`：修改文件权限 / 所属
    
    ```java
    $ hdfs dfs -chmod 777 文件地址
    
    $ hdfs dfs -chown zzay:zzay 文件地址
    ```
 *  `-cp`：将文件从 HDFS 的一个位置拷贝到 HDFS 的另一个位置
    
    ```java
    $ hdfs dfs -cp 源文件地址 目的地址
    ```
 *  `-mv`：在 HDFS 目录中移动文件
    
    ```java
    $ hdfs dfs -mv 源文件地址 目的地址
    ```
 *  `-tail`：显示一个文件末尾 1KB 的数据
    
    ```java
    $ hdfs dfs -tail 文件地址
    ```
 *  `-rm`：删除文件或文件夹
    
    ```java
    $ hdfs dfs -rm 文件地址
    ```
 *  `-rm -r`：递归删除目录及目录内的内容
    
    ```java
    $ hdfs dfs -rm -r 目录地址
    ```
 *  `-du -s -h`：统计文件夹/文件的大小信息
    
    ```java
    # 统计所给文件夹的大小信息
    $ hdfs dfs -du -s -h 文件夹地址
    
    # 统计所给文件夹内各文件的大小信息
    $ hdfs dfs -du -h 文件夹地址
    ```
 *  `-setrep`：设置 HDFS 中文件的副本数量
    
    ```java
    $ hdfs dfs -setrep 副本数量 文件地址
    ```

#### 2.2.2 上传 

 *  `-copyFromLocal`：将文件从本地复制粘贴到 HDFS
    
    ```java
    $ hdfs dfs -copyFromLocal 源文件地址 目的地址
    ```
 *  `-put`：将文件从本地复制粘贴到 HDFS（等同于`copyFromLocal`，生产环境更习惯用`put`）
    
    ```java
    $ hdfs dfs -put 源文件地址 目的地址
    ```
 *  `-moveFromLocal`：将文件从本地剪切到 HDFS
    
    ```java
    $ hdfs dfs -moveFromLocal 源文件地址 目的地址
    ```
 *  `-appendToFile`：追加一个文件到已存在的文件末尾
    
    ```java
    $ hdfs dfs -appendToFile 源文件地址 目的地址
    ```

#### 2.2.3 下载 

 *  `copyToLocal`：从 HDFS 下载文件到本地
    
    ```java
    $ hdfs dfs -copyToLocal 源文件地址 目的地址
    ```
 *  `get`：从 HDFS 下载文件到本地（等同于`copyToLocal`，生产环境更习惯用`get`）
    
    ```java
    $ hdfs dfs -get 源文件地址 目的地址
    ```

#### 2.2.4 进阶操作 

 *  `oiv`：查看 Fsimage 镜像文件（正常`cat`无法查看镜像文件，需要`oiv`协助转换）
    
    ```java
    $ hdfs oiv -p 转换后文件类型 -i 镜像文件 -o 转换后文件输出路径
    
    # Example（将镜像文件转换为xml文件 -> 直接查看/下载到本地查看）
    $ hdfs oiv -p XML -i fsimage_000000000000000025 -o /opt/module/hadoop-3.1.3/fsimage.xml
    $ cat /opt/module/hadoop-3.1.3/fsimage.xml
    $ sz /opt/module/hadoop-3.1.3/fsimage.xml
    ```
 *  `oev`：查看 Edits 编辑日志（正常`cat`无法查看 Edits 编辑日志，需要`oev`协助转换）
    
    ```java
    $ hdfs oev -p 转换后文件类型 -e 编辑日志 -o 转换后文件输出路径
    
    # Example（将Edits编辑日志转换为xml文件 -> 直接查看/下载到本地查看）
    $ hdfs oev -p XML -i edits_000000000000000012-000000000000000013 -o /opt/module/hadoop-3.1.3/edits.xml
    $ cat /opt/module/hadoop-3.1.3/edits.xml
    $ sz /opt/module/hadoop-3.1.3/edits.xml
    ```

### 2.3 YARN 命令 

```java
$ yarn COMMAND
```

 *  `yarn application`：查看任务相关信息
    
    ```java
    # 列出所有的Application
    $ yarn application -list
    
    # 根据Application状态，列出状态匹配的所有Application
    # （ALL, NEW, NEW_SAVING, SUBMITTED, ACCEPTED, RUNNING, FINISHED, FAILED, KILLED）
    $ yarn application -list -appStates <State>
    
    # 杀死对应的Application
    $ yarn application -kill <ApplicationId>
    
    # 修改applicationId对应的Application的优先级
    $ yarn application -applicationid <ApplicationId> -updatePriority <Priority>
    ```
 *  `yarn logs`：查看日志信息（Application日志、Container日志）
    
    ```java
    # 查看applicationId对应的Application的日志
    $ yarn logs -applicationId <ApplicationId>
    
    # 查看applicationId和containerId共同对应的Container的日志
    $ yarn logs -applicationId <ApplicationId> -containerId <ContainerId>
    ```
 *  `yarn applicationattempt`：查看尝试运行的任务的相关信息
    
    ```java
    # 查看applicationId对应的Application的所有运行尝试
    $ yarn applicationattempt -list <ApplicationId>
    
    # 查看applicationAttemptId对应的ApplicationAttempt的状态
    $ yarn applicationattempt -status <ApplicationAttemptId>
    ```
 *  `yarn container`：查看容器相关信息
    
    ```java
    # 查看与某次ApplicationAttempt相关的容器的信息，以及这次尝试的开始和结束时间 
    $ yarn container -list <ApplicationAttemptId>
    
    # 查看某个Container的状态（有任务运行时才能够显示）
    $ yarn container -status <ContainerId>
    ```
 *  `yarn node`：查看结点相关信息
    
    ```java
    # 列出所有结点
    $ yarn node -list -all
    ```
 *  `yarn rmadmin`：更新配置信息
    
    ```java
    # 加载队列配置
    $ yarn rmadmin -refreshQueues
    ```
 *  `yarn queue`：查看队列相关信息
    
    ```java
    # 根据所给队列名称，打印对应队列的状态信息
    $ yarn queue -status <QueueName>
    
    # 打印默认队列的状态信息
    $ yarn queue -status default
    ```

  


## 3. 重要图示 

> 以下包含`Hadoop 3.x`的一些重要图示（原理、流程）。

 *  ##### HDFS 写数据流程： 
    
    ![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/6a98ac43bd5d8a1b409352f8498a32ad.png#pic_center)
 *  ##### HDFS 读数据流程： 
    
    ![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/ea913e3f945064c751462cce2c1b422a.png#pic_center)
 *  ##### NameNode和Secondary NameNode的工作机制： 
    
    ![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/7529695045089bcdd2eab5c0edebb6c3.png#pic_center)
 *  ##### DataNode的工作机制： 
    
    ![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/d461880ecc33ab4bf63498f02969644a.png#pic_center)
 *  ##### MapReduce详细工作流程： 
    
    ![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/0bd8caf805168600797eec8d683619d9.png#pic_center)
    
    ![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/75c25b732f9c16d2624d1b0d65fada43.png#pic_center)

  


## 4. 常用脚本 

> 以下是 `Hadoop 3.x`常用的脚本。

 *  `xsync`：集群分发，向其他结点同步指定的文件（底层通过`rsync`实现）。
    
    ```java
    #!/bin/bash
    
    # 1.判断参数个数
    if [ $# -lt 1 ]
    then
        echo "Not Enough Arguement!"
        exit;
    fi
    
    # 2.遍历集群所有机器
    for host in hadoop102 hadoop103 hadoop104
    do
        echo "==================== $host ===================="
        # 3.遍历参数所给的所有目录，逐个分发
        for file in $@
        do 
            # 4.判断文件是否存在
            if [ -e $file ]
            then
                # 5.获取父目录
                pdir=$(cd -P $(dirname $file); pwd)
                # 6.获取当前文件
                fname=$(basename $file)
                ssh $host "mkdir -p $pdir"
                rsync -av $pdir/$fname $host:$pdir/
            else
                echo "$file does not exist!"
            fi
        done
    done
    ```
 *  `myhadoop.sh`：同时控制集群的启动与关闭。
    
    ```java
    #!/bin/bash
    
    if [ $# -lt 1 ]
    then
        echo "No Arguements Error..."
        exit;
    fi
    
    case $1 in
    "start")
        echo "===================== 启动 hadoop 集群 ===================="
    
        echo "--------------------- 启动 HDFS ---------------------"
        ssh hadoop102 "/opt/module/hadoop-3.1.3/sbin/start-dfs.sh"
        echo "--------------------- 启动 YARN ---------------------"
        ssh hadoop103 "/opt/module/hadoop-3.1.3/sbin/start-yarn.sh"
        echo "--------------------- 启动 historyserver ---------------------"
        ssh hadoop102 "/opt/module/hadoop-3.1.3/bin/mapred --daemon start historyserver"
    ;;
    "stop")
        echo "==================== 关闭 hadoop 集群 ===================="
    
        echo "--------------------- 关闭 historyserver ---------------------"
        ssh hadoop102 "/opt/module/hadoop-3.1.3/bin/mapred --daemon stop historyserver"
        echo "--------------------- 关闭 YARN ---------------------"
        ssh hadoop103 "/opt/module/hadoop-3.1.3/sbin/stop-yarn.sh"
        echo "--------------------- 关闭 HDFS ---------------------"
        ssh hadoop102 "/opt/module/hadoop-3.1.3/sbin/stop-dfs.sh"
    ;;
    *)
        echo "Input Arguements Error..."
    ;;
    esac
    ```
 *  `jpsall`：所有结点同时调用`jps`，用于获取当前各结点具体信息。
    
    ```java
    #!/bin/bash
    
    for host in hadoop102 hadoop103 hadoop104
    do
        echo "==================== $host ===================="
        ssh $host jps
    done
    ```

  


## 5. Java API 操作 

> 以下包含对`Hadoop3.x`在Java中相关API的调用操作演示实例。

 *  Maven配置：
    
    ```java
    <dependencies>
            <!-- https://mvnrepository.com/artifact/org.apache.hadoop/hadoop-client -->
            <dependency>
                <groupId>org.apache.hadoop</groupId>
                <artifactId>hadoop-client</artifactId>
                <version>3.1.3</version>
            </dependency>
            <!-- https://mvnrepository.com/artifact/junit/junit -->
            <dependency>
                <groupId>junit</groupId>
                <artifactId>junit</artifactId>
                <version>4.12</version>
            </dependency>
            <!-- https://mvnrepository.com/artifact/org.slf4j/slf4j-log4j12 -->
            <dependency>
                <groupId>org.slf4j</groupId>
                <artifactId>slf4j-log4j12</artifactId>
                <version>1.7.25</version>
            </dependency>
        </dependencies>
    
        <build>
            <plugins>
                <plugin>
                    <artifactId>maven-compiler-plugin</artifactId>
                    <version>3.6.1</version>
                    <configuration>
                        <source>1.8</source>
                        <target>1.8</target>
                    </configuration>
                </plugin>
                <plugin>
                    <artifactId>maven-assembly-plugin</artifactId>
                    <configuration>
                        <descriptorRefs>
                            <descriptorRef>jar-with-dependencies</descriptorRef>
                        </descriptorRefs>
                    </configuration>
                    <executions>
                        <execution>
                            <id>make-assembly</id>
                            <phase>package</phase>
                            <goals>
                                <goal>single</goal>
                            </goals>
                        </execution>
                    </executions>
                </plugin>
            </plugins>
    	</build>
    ```
 *  log4j.properties配置：
    
    ```java
    log4j.rootLogger=INFO, stdout
    log4j.appender.stdout=org.apache.log4j.ConsoleAppender
    log4j.appender.stdout.layout=org.apache.log4j.PatternLayout
    loq4j.appender.stdout.layout.ConversionPattern=%d %p [%c] - %m%n
    log4j.appender.logfile=org.apache.log4j.FileAppender
    log4j.appender.logfile.File=target/spring.log
    log4j.appender.logfile.layout=org.apache.log4j.PatternLayout
    log4j.appender.logfile.layout.ConversionPattern=%d %p [%c] - %m%n
    ```

### 5.1 HDFS 

> 以下包含 HDFS 在Java中相关API的调用操作。

 *  导入包：
    
    ```java
    import org.apache.hadoop.conf.Configuration;
    import org.apache.hadoop.fs.*;
    import org.junit.After;
    import org.junit.Before;
    import org.junit.Test;
    ```

#### 5.1.1 初始化及关闭 

```java
// HDFS client instance
private FileSystem fileSystem;

/**
 * Initialization.
 */
@Before
public void init() throws URISyntaxException, IOException, InterruptedException {
            
   
     
     
    // Address of the NameNode of the cluster connected
    URI nameNodeURI = new URI("hdfs://hadoop102:8020");
    // Hadoop Configuration
    Configuration configuration = new Configuration();
    // User
    String user = "zzay";

    // Get a HDFS client instance
    fileSystem = FileSystem.get(nameNodeURI, configuration, user);
}

/**
 * Close the hadoop file system.
 */
@After
public void close() throws IOException {
            
   
     
     
    fileSystem.close();
}
```

#### 5.1.2 基本操作 

```java
/**
 * Create a directory on HDFS.
 */
@Test
public void testMkdir() throws IOException {
            
   
     
     
    // File path string
    String dstPathStr = "hdfs://hadoop102/xiyou/huaguoshan";
    // File path
    Path dstPath = new Path(dstPathStr);

    fileSystem.mkdirs(dstPath);
}

/**
 * Put a file onto HDFS.
 * <p>
 * 参数说明：
 * (1) boolean delSrc: 是否删除源数据
 * (2) boolean overwrite: 若有目的路径有同名文件，是否覆盖
 * (3) Path/Path[] srcs/src: 源文件路径
 * (4) Path dst: 目标路径
 */
@Test
public void testPut() throws IOException {
            
   
     
     
    // File path string
    String srcPathStr = Objects.requireNonNull(this.getClass().getClassLoader().getResource("./texts/sunwukong.txt")).getPath();
    String dstPathStr = "hdfs://hadoop102//xiyou/huaguoshan";
    // File path
    Path srcPath = new Path(srcPathStr);
    Path dstPath = new Path(dstPathStr);

    fileSystem.copyFromLocalFile(false, false, srcPath, dstPath);
}

/**
 * Get a file from HDFS.
 * <p>
 * 参数说明：
 * (1) boolean delSrc: 是否删除源数据
 * (2) Path src: 源文件路径
 * (3) Path dst: 目标路径
 * (4) boolean useRawLocalFileSystem: 基本用不到
 */
@Test
public void testGet() throws IOException {
            
   
     
     
    // File path string
    String srcPathStr = "hdfs://hadoop102//xiyou/huaguoshan";
    String dstPathStr = "C:/Users/Dal-Z41/Desktop/sunwukong_get.txt";
    // File path
    Path srcPath = new Path(srcPathStr);
    Path dstPath = new Path(dstPathStr);

    fileSystem.copyToLocalFile(false, srcPath, dstPath);
}

/**
 * Remove a file on HDFS.
 * <p>
 * 参数说明：
 * (1) Path f: 目标文件路径
 * (2) boolean recursive: 是否递归删除
 */
@Test
public void testRm() throws IOException {
            
   
     
     
    // File path string
    String filepathStr = "hdfs://hadoop102/jdk-8u212-linux-x64.tar.gz";
    // File path
    Path filepath = new Path(filepathStr);

    fileSystem.delete(filepath, false);
}

/**
 * Rename a file/directory; move a file.
 * <p>
 * 参数说明：
 * (1) Path src: 源文件路径
 * (2) Path dst: 目标文件路径
 * (2) boolean recursive: 是否递归删除
 */
@Test
public void testRenameAndMove() throws IOException {
            
   
     
     
    // File path string
    String srcPathStr = "hdfs://hadoop102/input/word.txt";
    String newNameStr = "hdfs://hadoop102/input/ss.txt";
    String dstPathStr = "hdfs://hadoop102/cls.txt";

    // File path
    Path srcPath = new Path(srcPathStr);
    Path newNamePath = new Path(newNameStr);
    Path dstPath = new Path(dstPathStr);

    // Rename
    fileSystem.rename(srcPath, newNamePath);
    // Move
    fileSystem.rename(newNamePath, dstPath);
}
```

#### 5.1.3 进阶操作 

 *  查看某个文件的详细信息（权限，所属，所在组，大小，最近修改时间，副本数，块大小，名称，块信息）：
    
    ```java
    /**
     * Get detailed information of a file.
     * <p>
     * 参数说明：
     * (1) Path f: 目标文件路径
     * (2) boolean recursive: 是否递归查询
     */
    @Test
    public void getFileDetails() throws IOException {
                  
         
           
           
        // File path string
        String filepathStr = "hdfs://hadoop102/";
        // File path
        Path filepath = new Path(filepathStr);
    
        // Get a list of files and traverse them
        RemoteIterator<LocatedFileStatus> listFiles = fileSystem.listFiles(filepath, true);
        while (listFiles.hasNext()) {
                  
         
           
           
            // Each file stored in HDFS
            LocatedFileStatus fileStatus = listFiles.next();
            // Block locations of each file
            BlockLocation[] blockLocations = fileStatus.getBlockLocations();
            System.out.println("==========" + fileStatus.getPath() + "==========");
            System.out.println("Permission: " + fileStatus.getPermission());
            System.out.println("Owner: " + fileStatus.getOwner());
            System.out.println("Group: " + fileStatus.getGroup());
            System.out.println("Size: " + fileStatus.getLen());
            System.out.println("Last Modified: " + fileStatus.getModificationTime());
            System.out.println("Replication: " + fileStatus.getReplication());
            System.out.println("Block Size: " + fileStatus.getBlockSize());
            System.out.println("Name: " + fileStatus.getPath().getName());
            System.out.println("Block locations: " + Arrays.toString(blockLocations));
        }
    }
    ```
 *  判断给定对象是文件还是文件夹：
    
    ```java
    /**
     * Judge whether the given object is a file or a directory.
     * <p>
     * 参数说明：
     * (1) Path/Path[] f/files: 目标文件路径
     * (2) PathFilter filter: 路径过滤器
     */
    @Test
    public void testFileOrDir() throws IOException {
                  
         
           
           
        // File path string
        String filepathStr = "hdfs://hadoop102/";
        // File path
        Path filepath = new Path(filepathStr);
    
        // Get file statuses and traverse them
        FileStatus[] fileStatuses = fileSystem.listStatus(filepath);
        for (FileStatus fileStatus : fileStatuses) {
                  
         
           
           
            if (fileStatus.isFile()) {
                  
         
           
           
                System.out.println("File: " + fileStatus.getPath().getName());
            } else if (fileStatus.isDirectory()) {
                  
         
           
           
                System.out.println("Directory: " + fileStatus.getPath().getName());
            }
        }
    }
    ```

### 5.2 MapReduce 

> 以下包含 MapReduce 在Java中相关API的调用操作，以举例形式记录。

#### 5.2.1 Basics - WordCount 

 *  WordCountMapper： 读取数据文件，对单词进行切割，并以（xxx，1）的形式存储到最终要输出到Reducer的K-V对中。
    
    ```java
    package com.zzay.mapreduce.wordcount;
    
    import org.apache.hadoop.io.IntWritable;
    import org.apache.hadoop.io.LongWritable;
    import org.apache.hadoop.io.Text;
    import org.apache.hadoop.mapreduce.Mapper;
    
    import java.io.IOException;
    
    /**
     * @author zzay
     * @className WordCountMapper
     * @description 读取数据文件，对单词进行切割，并以（xxx，1）的形式存储到最终要输出到Reducer的K-V对中。
     * 【Mapper泛型参数说明】
     * KEYIN:    map阶段输入的key的类型：LongWritable
     * VALUEIN:  map阶段输入value类型：Text
     * KEYOUT:   map阶段输出的Key类型：Text
     * VALUEOUT: map阶段输出的value类型：IntWritable
     * @create 2022/03/29 13:06
     */
    public class WordCountMapper extends Mapper<LongWritable, Text, Text, IntWritable> {
                  
         
           
           
    
        // Output key of the final K-V pair sent to Reducer
        private final Text outKey = new Text();
    
        // Output value of the final K-V pair sent to Reducer
        private final IntWritable outValue = new IntWritable(1);
    
        /**
         * 读取数据文件，对单词进行切割，并存储到最终要输出到Reducer的K-V对中。
         *
         * @param key     该单词在所给数据中的偏移量
         * @param value   单词字符串
         * @param context 关联Mapper和Reducer及系统代码的上下文对象
         */
        @Override
        protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
                  
         
           
           
            // (1) Read a line of data
            String lineData = value.toString();
    
            // (2) Split words
            String[] words = lineData.split(" ");
    
            // (3) Traverse and write out to the final output K-V pair sent to Reducer
            for (String word: words) {
                  
         
           
           
                outKey.set(word);
                context.write(outKey, outValue);
            }
        }
    
    }
    ```
 *  WordCountReducer： 根据上下文对象，获得Mapper的最终输出。根据输出，统计各个单词的出现次数，并存入到最终输出的K-V对中。
    
    ```java
    package com.zzay.mapreduce.wordcount;
    
    import org.apache.hadoop.io.IntWritable;
    import org.apache.hadoop.io.Text;
    import org.apache.hadoop.mapreduce.Reducer;
    
    import java.io.IOException;
    
    /**
     * @author zdz
     * @className WordCountReducer
     * @description 根据上下文对象，获得Mapper的最终输出。根据输出，统计各个单词的出现次数，并存入到最终输出的K-V对中。
     * 【Reducer泛型参数说明】
     * KEYIN:    reduce阶段输入的key的类型：Text
     * VALUEIN:  reduce阶段输入value类型：IntWritable
     * KEYOUT:   reduce阶段输出的Key类型：Text
     * VALUEOUT: reduce阶段输出的value类型：IntWritable
     * @create 2022/03/29 13:06
     */
    public class WordCountReducer extends Reducer<Text, IntWritable, Text, IntWritable> {
                  
         
           
           
    
        // Record the occurrence times of each word
        IntWritable outValue = new IntWritable();
    
        /**
         * 根据上下文对象，获得Mapper的最终输出。根据输出，统计各个单词的出现次数，并存入到最终输出的K-V对中。
         *
         * @param key     单词字符串
         * @param values  输入value固定为1
         * @param context 关联Mapper和Reducer及系统代码的上下文对象
         */
        @Override
        protected void reduce(Text key, Iterable<IntWritable> values, Context context) throws IOException, InterruptedException {
                  
         
           
           
            int sum = 0;
    
            for (IntWritable value : values) {
                  
         
           
           
                sum += value.get();
            }
            outValue.set(sum);
    
            context.write(key, outValue);
    
        }
    
    }
    ```
 *  WordCountDriver： 关联Mapper、Reducer和系统代码，定义输入输出格式，实现业务逻辑。
    
    ```java
    package com.zzay.mapreduce.wordcount;
    
    import org.apache.hadoop.conf.Configuration;
    import org.apache.hadoop.fs.Path;
    import org.apache.hadoop.io.IntWritable;
    import org.apache.hadoop.io.Text;
    import org.apache.hadoop.mapreduce.Job;
    import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
    import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
    
    import java.io.IOException;
    
    /**
     * @author zdz
     * @className WordCountDriver
     * @description 关联Mapper、Reducer和系统代码，定义输入输出格式，实现业务逻辑。
     * @create 2022/03/29 13:06
     */
    public class WordCountDriver {
                  
         
           
           
    
        public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
                  
         
           
           
            // (1) 获取配置信息，获取job对象实例
            Job job = Job.getInstance(new Configuration());
    
            // (2) 指定本程序的jar包所在的本地路径
            job.setJarByClass(WordCountDriver.class);
    
            // (3) 关联Mapper/Reducer业务类
            job.setMapperClass(WordCountMapper.class);
            job.setReducerClass(WordCountReducer.class);
    
            // (4) 指定Mapper输出数据的K-V类型
            job.setMapOutputKeyClass(Text.class);
            job.setMapOutputValueClass(IntWritable.class);
    
            // (5) 指定最终输出数据的K-V类型
            job.setOutputKeyClass(Text.class);
            job.setOutputValueClass(IntWritable.class);
    
            // (6) 指定job的输入原始文件所在目录，job的输出结果所在目录
            FileInputFormat.setInputPaths(job, new Path("..."));
            FileOutputFormat.setOutputPath(job, new Path("..."));
    
            // (7) 提交作业
            boolean result = job.waitForCompletion(true);
    
            System.exit(result ? 0 : 1);
        }
    
    }
    ```

#### 5.2.2 Serialization序列化、Partition分区、Comparable比较策略 

本例子主要演示：

1.  序列化及反序列化自定义类实例对象；
2.  对输出进行自定义分区；
3.  如果自定义排序规则。

 *  ProvincePartitioner： 根据省份对信息进行分区。
    
    ```java
    /**
     * @author zzay
     * @className ProvincePartitioner
     * @description 根据省份对信息进行分区
     * [参数说明]
     * KEY：根据KEY的内部细节，制定相应的分区策略
     * VALUE：该KEY对应的Value数据
     * @create 2022/03/29 21:32
     */
    public class ProvincePartitioner extends Partitioner<FlowBean, Text> {
                  
         
           
           
    
        /**
         * 根据所给数据信息，判断该数据应分配的分区，并返回相应的分区ID。
         *
         * @param flowBean      一条数据
         * @param text          手机号
         * @param numPartitions 分区总数目
         * @return 给这条数据所分配的分区ID
         */
        @Override
        public int getPartition(FlowBean flowBean, Text text, int numPartitions) {
                  
         
           
           
            // Original phone number
            String phone = text.toString();
            // Prefix of the phone number
            String phonePrefix = phone.substring(0, 3);
            // ID of the partition the current data should be allocated
            int partition;
    
            if ("136".equals(phonePrefix)) {
                  
         
           
           
                partition = 0;
            } else if ("137".equals(phonePrefix)) {
                  
         
           
           
                partition = 1;
            } else if ("138".equals(phonePrefix)) {
                  
         
           
           
                partition = 2;
            } else if ("139".equals(phonePrefix)) {
                  
         
           
           
                partition = 3;
            } else {
                  
         
           
           
                partition = 4;
            }
            return partition;
        }
    
    }
    ```
 *  FlowBean： 模拟自定义的类实例对象。
    
    1、定义类实现`WritableComparable`接口，从而能够进行序列化和反序列化，以及自定义比较策略。
    
    2、重写序列化方法`write`和反序列化方法`readFields`。
    
    3、重写空参构造。
    
    4、`toString`方法。
    
    ```java
    /**
     * @author zzay
     * @className FlowBean
     * @description 模拟需要序列化传输的Bean对象
     * 1、定义类实现writable接口
     * 2、重写序列化和反序列化方法
     * 3、重写空参构造
     * 4、toString方法
     * @create 2022/03/29 16:06
     */
    public class FlowBean implements WritableComparable<FlowBean> {
                  
         
           
           
    
        // Up Flow
        private long upFlow;
        // Down flow
        private long downFlow;
        // Sum of upFlow and downFlow
        private long sumFlow;
        // No-args constructor
        public FlowBean() {
                  
         
           
           }
    
        /**
         * Serialization.
         *
         * @param out DataOutput
         */
        @Override
        public void write(DataOutput out) throws IOException {
                  
         
           
           
            out.writeLong(upFlow);
            out.writeLong(downFlow);
            out.writeLong(sumFlow);
        }
    
        /**
         * DeSerialization.
         *
         * @param in DataInput
         */
        @Override
        public void readFields(DataInput in) throws IOException {
                  
         
           
           
            this.upFlow = in.readLong();
            this.downFlow = in.readLong();
            this.sumFlow = in.readLong();
        }
    
        @Override
        public int compareTo(FlowBean o) {
                  
         
           
           
            if (this.sumFlow > o.sumFlow) {
                  
         
           
           
                return -1;
            } else if (this.sumFlow < o.sumFlow) {
                  
         
           
           
                return 1;
            } else {
                  
         
           
           
                if (this.upFlow > o.upFlow) {
                  
         
           
           
                    return 1;
                } else if (this.upFlow < o.upFlow) {
                  
         
           
           
                    return -1;
                } else {
                  
         
           
           
                    return 0;
                }
            }
        }
    
        @Override
        public String toString() {
                  
         
           
           
            return upFlow + "\t" +
                    downFlow + "\t" +
                    sumFlow;
        }
    
        public void setSumFlow() {
                  
         
           
           
            this.sumFlow = this.upFlow + this.downFlow;
        }
        
    	// ...
        
    }
    ```
 *  FlowMapper： 负责序列化业务的Mapper类。
    
    ```java
    /**
     * @author zzay
     * @className FlowMapper
     * @description 序列化业务的Mapper类
     * @create 2022/03/29 16:11
     */
    public class FlowMapper extends Mapper<LongWritable, Text, FlowBean, Text> {
                  
         
           
           
    
        // Output value: FlowBean instance
        private final FlowBean outKey = new FlowBean();
        // Output key: String phone
        private final Text outValue = new Text();
    
        /**
         * Map过程。
         *
         * @param key     数据的行ID
         * @param value   一行数据
         * @param context 关联Mapper，Reducer和系统代码的上下文对象
         */
        @Override
        protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
                  
         
           
           
            // (1) Get a line of data
            String lineData = value.toString();
    
            // (2) Split the lineData
            // [id, phone, ip, domainName, upFlow, downFlow, status]
            String[] data = lineData.split("\t");
    
            // (3) Get data expected (phone, flows)
            String phone = data[0];
            String upFlow = data[1];
            String downFlow = data[2];
    
            // (4) Encapsulate data
            outKey.setUpFlow(Long.parseLong(upFlow));
            outKey.setDownFlow(Long.parseLong(downFlow));
            outKey.setSumFlow();
            outValue.set(phone);
    
            // (5) Write out
            context.write(outKey, outValue);
        }
    
    }
    ```
 *  FlowReducer： 负责序列化业务的Reducer类
    
    Mapper 输出的 Key 为`FlowBean`对象，即一行数据；输出的 Value 为手机号。
    
    通常来说，一个 key 可能对应多个 value 。但是这种情况下，一个 key（一行数据）只能对应一个 value（手机号），因为基本不可能有两行数据完全一样而不属于一个手机号。  
    所以说，此时的 Reducer 相当于没有做额外操作，只是将 key 和 value 的位置进行反转。
    
    ```java
    /**
     * @author zzay
     * @className FlowReducer
     * @description 负责序列化业务的Reducer类
     * @create 2022/03/29 16:21
     */
    public class FlowReducer extends Reducer<FlowBean, Text, Text, FlowBean> {
                  
         
           
           
    
        /**
         * Reduce过程。
         * Mapper输出的Key为FlowBean对象，即一行数据；输出的Value为手机号。
         * 通常来说，一个key可能对应多个value。但是这种情况下，一个key（一行数据）只能对应一个value（手机号），因为基本不可能有两行数据完全一样而不属于一个手机号。
         * 所以说，此时的Reducer相当于没有做额外操作，只是将key和value的位置进行反转。
         *
         * @param key     一行数据（手机号，流量）
         * @param values  Mapper提取出的手机号
         * @param context 关联Mapper，Reducer和系统代码的上下文对象
         */
        @Override
        protected void reduce(FlowBean key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
                  
         
           
           
            for (Text value : values) {
                  
         
           
           
                // 实际上只会进行一轮
                context.write(value, key);
            }
        }
    
    }
    ```
 *  FlowDriver： 关联Mapper、Reducer和系统代码，定义最终输入输出格式，实现业务逻辑。
    
    需要注意自定义分区时，需要加入`job.setPartitionerClass`来设置自定义的分区类配置。
    
    此外，还需要记得设置 ReduceTask 的数目，以合理匹配分区数目。
    
    ```java
    /**
     * @author zzay
     * @className FlowDriver
     * @description 关联Mapper、Reducer和系统代码，定义最终输入输出格式，实现业务逻辑。
     * @create 2022/03/29 16:26
     */
    public class FlowDriver {
                  
         
           
           
    
        public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
                  
         
           
           
            // ...
            
            // 设置自定义的分区策略
            job.setPartitionerClass(ProvincePartitioner.class);
            // 设置ReduceTask的数目，以合理匹配分区数目
            job.setNumReduceTasks(5);
    
            // ...
        }
    
    }
    ```

#### 5.2.3 Combiner机制 

基于先前的WordCount例子延伸。

- 核心：引入`Combiner`类 / 以 `Reducer` 类自身作为 CombinerClass。

- 主要功能：对每个 MapTask 的输出做局部汇总，以减轻最终 Reducer 处理输入时所需的磁盘IO。

- 注意点：不影响最终的业务逻辑；在每个 MapTask 所在的结点运行。

 *  WordCountCombiner： `WordMapper` 和 `WordReducer` 之间的 Combiner。
    
    ```java
    /**
     * @author zzay
     * @className WordCountCombiner
     * @description WordMapper和WordReducer之间的Combiner类
     * @create 2022/03/30 00:13
     * @see com.zzay.mapreduce.combiner.normal.WordCountMapper
     * @see com.zzay.mapreduce.combiner.normal.WordCountReducer
     */
    public class WordCountCombiner extends Reducer<Text, IntWritable, Text, IntWritable> {
                  
         
           
           
    
        private final IntWritable outValue = new IntWritable();
    
        /**
         *
         * @param key     单词字符串
         * @param values  输入value固定为1
         * @param context 关联Mapper和Reducer及系统代码的上下文对象
         */
        @Override
        protected void reduce(Text key, Iterable<IntWritable> values, Context context) throws IOException, InterruptedException {
                  
         
           
           
            int sum = 0;
            for (IntWritable value: values) {
                  
         
           
           
                sum += value.get();
            }
            outValue.set(sum);
            context.write(key, outValue);
        }
    
    }
    ```
 *  WordCountDriver： 关联Mapper、Reducer和系统代码，定义输入输出格式，实现业务逻辑。
    
    ```java
    /**
     * @author zdz
     * @className WordCountDriver
     * @description 关联Mapper、Reducer和系统代码，定义输入输出格式，实现业务逻辑。
     * @create 2022/03/29 13:06
     */
    public class WordCountDriver {
                  
         
           
           
    
        public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
                  
         
           
           
            // ...
    
            // 配置Combiner类
            job.setCombinerClass(WordCountCombiner.class);
    		
            // ...
        }
    
    }
    ```
 *  ：
    
    ```java
    
    ```

### 5.3 YARN 

 *  ：
    
    ```java
    
    ```