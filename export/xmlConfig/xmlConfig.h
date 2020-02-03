// =====================================================================================
// 
//       Filename:  xmlConfig.h
// 
//    Description:  xml配置文件接口
// 
//        Version:  1.0
//        Created:  03/17/2010 10:10:24 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Zou.Qiang (Zq), zoutaiqi@gmail.com
//        Company:  vimicro.com
// 
// =====================================================================================
#ifndef _XML_CONFIG_H_
#define _XML_CONFIG_H_

#include <string>
#include <map>

class TiXmlDocument;
class xmlConfig
{
public:
	/*
	 *功能描述: SingleTon模式创建实例
	 *输入参数: 无
	 *输出参数: 无
	 *返回值: xmlConfig类型,非NULL为成功,NULL为失败
	*/
	static xmlConfig *GetInstance();

	/*
	 *功能描述: Destroy Instance
	 *输入参数: 无
	 *输出参数: 无
	 *返回值: 无
	*/
	void DestroyInstance();

	/*
	 *功能描述: 加载xml类型配置文件
	 *输入参数: strXmlFileName:配置文件名
	 *输出参数: 无
	 *返回值: bool类型,true为成功,false为失败
	*/
	bool LoadConfig(const std::string &strXmlFileName);

	/*
	 *功能描述: 初始化一个xml节点的缺省值
	 *输入参数: 
	 *			strTag:类型const string &,一个xml节点的tag标签,如<Item>Value</Item>节点, strTag=="Item",
	 *				   如果是嵌套节点,如<Item><ChildItem>Value</ChildItem></Item>,strTag=="Item.ChildItem"
	 *				   strTag的长度必须小于512字节
	 *			strDefaultValue:类型const string &,节点strTag的缺省值Value
	 *输出参数: 无
	 *返回值: 无
	*/
	void AddNodeDefaultValue(const std::string &strTag, const std::string &strDefaultValue);

	/*
	 *功能描述: 初始化一个xml节点的缺省值
	 *输入参数: 
	 *			strTag:类型const string &,一个xml节点的tag标签,如<Item>Value</Item>节点, strTag=="Item",
	 *				   如果是嵌套节点,如<Item><ChildItem>Value</ChildItem></Item>,strTag=="Item.ChildItem"
	 *				   strTag的长度必须小于512字节
	 *			nDefaultValue:类型const int &,节点strTag的缺省值Value
	 *输出参数: 无
	 *返回值: 无
	*/
	void AddNodeDefaultValue(const std::string &strTag, const int &nDefaultValue);

	/*
	 *功能描述: 初始化一个xml节点的缺省值
	 *输入参数: 
	 *			strTag:类型const string &,一个xml节点的tag标签,如<Item>Value</Item>节点, strTag=="Item",
	 *				   如果是嵌套节点,如<Item><ChildItem>Value</ChildItem></Item>,strTag=="Item.ChildItem"
	 *				   strTag的长度必须小于512字节
	 *			bDefaultValue:类型const bool &,节点strTag的缺省值Value
	 *输出参数: 无
	 *返回值: 无
	*/
	void AddNodeDefaultValue(const std::string &strTag, const bool &bDefaultValue);

	/*
	 *功能描述: 获取一个xml节点的值
	 *输入参数: 
	 *			strTag:类型const string &,一个xml节点的tag标签,如<Item>Value</Item>节点, strTag=="Item",
	 *				   如果是嵌套节点,如<Item><ChildItem>Value</ChildItem></Item>,strTag=="Item.ChildItem"
	 *				   strTag的长度必须小于512字节
	 *输出参数: 无
	 *返回值: string类型, 节点strTag的值Value
	*/
	std::string GetNodeValueString(const std::string &strTag);

	/*
	 *功能描述: 获取一个xml节点的值
	 *输入参数: 
	 *			strTag:类型const string &,一个xml节点的tag标签,如<Item>Value</Item>节点, strTag=="Item",
	 *				   如果是嵌套节点,如<Item><ChildItem>Value</ChildItem></Item>,strTag=="Item.ChildItem"
	 *				   strTag的长度必须小于512字节
	 *输出参数: 无
	 *返回值: int类型, 节点strTag的值Value
	*/
	int GetNodeValueInt(const std::string &strTag);

	/*
	 *功能描述: 获取一个xml节点的值
	 *输入参数: 
	 *			strTag:类型const string &,一个xml节点的tag标签,如<Item>Value</Item>节点, strTag=="Item",
	 *				   如果是嵌套节点,如<Item><ChildItem>Value</ChildItem></Item>,strTag=="Item.ChildItem"
	 *				   strTag的长度必须小于512字节
	 *输出参数: 无
	 *返回值: bool类型, 节点strTag的值Value
	*/
	bool GetNodeValueBool(const std::string &strTag);

private:
	/*
	 *功能描述: 收到重新加载配置文件信号时，重新加载xml类型配置文件
	 *输入参数: 无
	 *输出参数: 无
	 *返回值: bool类型,true为成功,false为失败
	*/
	static void ReLoadConfig(int signo);
	
	void ClearDoc();
	void LoadConfig();
protected:
	xmlConfig();
	virtual ~xmlConfig();

private:
	static xmlConfig *s_lpxmlConfig;

	std::string m_strXmlFileName;
	std::map<std::string, std::string> m_mpDefaultValue;

	TiXmlDocument *m_lpDocument;

	//lock
};

#endif
