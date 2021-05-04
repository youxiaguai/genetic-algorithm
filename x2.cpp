//#include "x2Genetic.h"
//using namespace std;
////自变量取值范围向量和种群向量定义
//const X_Range Range = { X_Range(-3.0,12.1) };//自变量（或者基因）x1,x2的取值范围
//vector<Individual> nowpopulation;//P(t)种群
//vector<Individual> midpopulation;//中间种群，存放轮盘选择后的优秀个体
//vector<Individual> nextpopulation;//P(t+1)种群
////X_Range类实现
//X_Range::X_Range(double m_Lower, double m_Upper) :Lower(m_Lower), Upper(m_Upper) {}//X_Range类构造函数实现
//double X_Range::GetUpper()const//获取变量上限
//{
//    return Upper;
//}
//double X_Range::GetLower()const//获取变量下限
//{
//    return Lower;
//}
////Individual类实现
//Individual::Individual(double m_Variable)//构造函数
//{
//   
//    
//        if (m_Variable >= Range.GetLower() && m_Variable <= Range.GetUpper())//这里要进行自变量取值范围判断
//        {
//            Variable = m_Variable;//自变量赋值
//        }
//        else//不满足要求则发出出错警告并返回
//        {
//            cerr << "自变量取值不满足要求" << endl;
//            exit(1);//停止程序，我会以随机函数的方式生成自变量的值(基因值)，这里说明基因值不在规定范围内
//        }
//    
//    //初始化时默认适应值等值为0
//    this->Fitness = 0;
//    this->ReFitness = 0;
//    this->SumFitness = 0;
//}
//double Individual::GetVariable()//获取基因值
//{
//    return Variable;
//}
//double Individual::GetFitness()const//获取适应值
//{
//    return Fitness;
//}
//double Individual::GetReFitness()const //获取适应值概率
//{
//    return ReFitness;
//}
//double Individual::GetSumFitness()const//获取累加概率
//{
//    return SumFitness;
//}
//void Individual::ChaFitness(const double m_fitness)//修改适应值
//{
//    this->Fitness = m_fitness;
//}
//void Individual::ChaReFitness(const double m_ReFitness)//修改适应值概率
//{
//    this->ReFitness = m_ReFitness;
//}
//void Individual::ChaSumFitness(const double m_SumFitness)//修改累加概率
//{
//    this->SumFitness = m_SumFitness;
//}
////遗传算法的准备工作
//void Initialize()//随机初始化种群，得到第一代种群
//{
//    //产生指定范围的随机变量（基因）
//    double X[Po_Size];//为了使程序可以满足多元函数最值的计算，用矩阵保存产生的随机数变量值
//    default_random_engine e(time(0));//引擎，生成随机序列
//    uniform_real_distribution<double> u(Range.GetLower(), Range.GetUpper());//分布
//    for (int i = 0; i < Po_Size; i++)//先按列存储随机数
//    {
//         X[i] = u(e);//循环结束时，所有随机值就保存在X矩阵中
//    }
//    
//    //生成对象（染色体）并加入到初始种群中
//    for (int i = 0; i < Po_Size; i++)
//    {
//        double variable;
//        
//            variable = X[i];//按行保存
//        
//        Individual Indivi(variable);//生成一个对象（染色体）
//        nowpopulation.push_back(Indivi);//加入到种群population中
//    }
//}
//void CaculaFitness()//计算个体的适应值
//{
//    //f(x) = x^2+1 为适应度计算函数
//    double fitness = 0;//临时适应值
//    double x;//临时存储自变量（基因）
//    for (int i = 0; i < Po_Size; i++)
//    {
//        
//        x = nowpopulation.at(i).GetVariable();//这样更直观
//        fitness =(x*x)+ 1;//适应度计算 
//        nowpopulation.at(i).ChaFitness(fitness);//修改当前染色体的适应值
//    }
//}
//void CaculaReFitness()//计算适应值概率
//{
//    double sum = 0;//适应值累加器
//    double temp = 0;
//    for (int i = 0; i < Po_Size; i++)//计算出适应值之和
//    {
//        sum += nowpopulation.at(i).GetFitness();
//    }
//    for (int j = 0; j < Po_Size; j++)
//    {
//        temp = nowpopulation.at(j).GetFitness() / sum;//计算概率
//        nowpopulation.at(j).ChaReFitness(temp);//修改个体的适应度概率
//    }
//}
//void CalculaSumFitness()//计算累加个体概率
//{
//    double summation = 0;//累加器
//    for (int k = 0; k < Po_Size; k++)
//    {
//        summation += nowpopulation.at(k).GetReFitness();
//        nowpopulation.at(k).ChaSumFitness(summation);//当前累加结果赋值
//    }
//}
//void seclect() //种群选择
//{
//    //随机生生成0到1的小数
//    double array[Po_Size];//随机数保存变量
//    default_random_engine e(time(0));//引擎，生成随机序列
//    uniform_real_distribution<double> u(0.0, 1.0); //分布
//    for (int i = 0; i < Po_Size; i++)
//        array[i] = u(e);
//    //轮盘进行选择
//    for (int j = 0; j < Po_Size; j++)
//    {
//        for (int i = 1; i < Po_Size; i++)
//        {
//            if (array[j] < nowpopulation[i - 1].GetSumFitness())
//            {
//                midpopulation.push_back(nowpopulation.at(i - 1));//加入到中间种群
//            }
//            if (array[j] >= nowpopulation.at(i - 1).GetSumFitness() && array[j] <= nowpopulation.at(i).GetSumFitness())
//            {
//                midpopulation.push_back(nowpopulation.at(i));//加入到中间种群
//            }
//        }
//    }
//    nowpopulation.clear();//清空nowpopulation
//}
//double Scand() //随机产生0到1的小数
//{
//    int N = rand() % 999;
//    return double(N) / 1000.0;;//随机产生0到1的小数
//}
//void crossing()//杂交
//{
//    int num = 0;//记录次数
//    double corss = 0.0;//保存随机产生的概率值
//    srand((unsigned)time(NULL));//根据系统时间设置随机数种子,设置一次随机种子就行
//    double array1, array2;//临时存储父亲和母亲的变量值
//    while (num < Po_Size - 1)//个体1与个体2杂交，个体3与个体4杂交......个体i和个体i+1杂交
//    {
//        //判断双亲是否需要杂交，随机生成一个0到1的小数，如果这个数大于杂交概率，则放弃杂交，直接遗传给下一代，否则，对父母体进行杂交
//        corss = Scand();
//        if (corss <= Ov_Probability)//如果corss小于等于杂交概率Ov_Probability就进行单点杂交
//        {
//            //首先寻找对应下标的个体并且保存
//            
//                array1 = midpopulation.at(num).GetVariable();//父亲的自变量
//                array2 = midpopulation.at(num + 1).GetVariable();//母亲自变量
//            
//            int localx1, localx2;//记录基因交叉点的位置
//            int corssx[length];//作为交换基因的数组
//            double newx1, newx2;//分别用来保存基因交换后所对应自变量值
//            bool p1 = true, p2 = true;
//            //然后对双亲变量进行编码并且进行单点杂交
//           
//                
//                
//            bitset<length> array1b2((array1) * pow(10, 6));//母体1的x2编码
//            bitset<length> array2b2((array2) * pow(10, 6));//母体2的x2编码
//            //现在随机生成0到length2-1的数，确定交叉点的位置
//            localx2 = rand() % length;
//            //现在进行单点交叉，交换双亲localx2后面的基因
//            for (int i = 0; i < localx2; i++)
//                corssx[i] = array1b2[i];
//            for (int k = 0; k < localx2; k++)
//                array1b2[k] = array2b2[k];
//            for (int s = 0; s < localx2; s++)
//                array2b2[s] = corssx[s];
//            //新值保存在newx2数组中，x2基因完成单点杂交操作
//            newx1 = double(array1b2.to_ullong()) / pow(10, 6);
//            newx2 = double(array2b2.to_ullong()) / pow(10, 6);
//            //对新产生的值进行判断，判断是否超出范围，如果超出范围则不杂交
//            if (newx1< Range.GetLower() || newx1>Range.GetUpper() || newx2<Range.GetLower() || newx2>Range.GetUpper())
//            {
//                p2 = false;
//                break;
//            }
//                
//            
//            if (p1 == true && p2 == true)
//            {
//                Individual newchiled1(newx1);
//                Individual newchiled2(newx2);
//                nextpopulation.push_back(newchiled1);
//                nextpopulation.push_back(newchiled2);
//            }
//            else//将原来的个体遗传给下一代
//            {
//                nextpopulation.push_back(midpopulation.at(num));
//                nextpopulation.push_back(midpopulation.at(num + 1));
//            }
//        }
//        else//否则直接遗传给下一代nextpopulation
//        {
//            nextpopulation.push_back(midpopulation.at(num));//生成一个新的个体并且加入到nextpopulation中
//            nextpopulation.push_back(midpopulation.at(num + 1));
//        }
//        num += 2;
//    }
//    midpopulation.clear();//清空midpopulation
//}
//void variating()//变异
//{
//    int num = 0;
//    while (num < Po_Size)
//    {
//        double variation = Scand();//随机产生一个0到1的小数，用于判断是否进行变异
//        if (variation <= Va_Probability)//如果variation小于变异系数，则需要进行变异
//        {
//            double x;
//            bool p = true;
//            int xlocal, 
//            x = nextpopulation.at(num).GetVariable();
//            bitset<length> array(x * pow(10, 6));//x编码
//            xlocal = rand() % length;//array该位取反
//           
//            
//            array.flip(xlocal);//改变array2 x2local位的状态
//           
//            x = double(array.to_ullong()) / pow(10, 6);
//            //判断是否符合条件
//            if (x< Range.GetLower() || x>Range.GetUpper() || x<Range.GetLower() || x>Range.GetUpper())
//                p = false;
//            if (!p)//如果不符合，则将不变异的值加入新的里面
//                nowpopulation.push_back(nextpopulation.at(num));
//            if (p) //p为真的话，将变异后的加入新的里面进行迭代
//            {
//                Individual newchiled(x);
//                nowpopulation.push_back(newchiled);
//            }
//        }
//        else //不变异
//            nowpopulation.push_back(nextpopulation.at(num));
//        num++;
//    }
//    nextpopulation.clear();//清空nextpopulation
//}
//void genetic_algorithm()
//{
//    Initialize();//初始化种群,随机生成第一代个体
//    //进化500代
//    for (int i = 0; i < Ev_Algebra; i++)
//    {
//        CaculaFitness();//适应度计算
//        CaculaReFitness();//适应度概率计算
//        CalculaSumFitness();//计算累加个体概率
//        seclect();//选择
//        crossing();//杂交
//        variating();//变异
//    }
//    CaculaFitness();//适应度计算
//    double maxfitness = nowpopulation.at(0).GetFitness();
//    int maxid = 0;
//    int k;
//    for (k = 0; k < Po_Size; k++)
//    {
//        if (maxfitness < nowpopulation.at(k).GetFitness())
//        {
//            maxfitness = nowpopulation.at(k).GetFitness();
//            maxid = k;
//        }
//    }
//    //进化500代之后输出
//    cout << "x" << setw(15) << "Fitness" << endl;
//    for (int j = 0; j < Po_Size; j++)
//        cout << nowpopulation.at(j).GetVariable() << setw(10)  << nowpopulation.at(j).GetFitness() << endl;
//    cout << "x=" << nowpopulation.at(maxid).GetVariable()  << "时取得最大值：" << maxfitness << endl;
//}
//int main()
//{
//    genetic_algorithm();
//    return 0;
//}
// 
// 
