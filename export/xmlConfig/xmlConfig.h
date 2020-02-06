// =====================================================================================
// 
//       Filename:  xmlConfig.h
// 
//    Description:  xml�����ļ��ӿ�
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
	 *��������: SingleTonģʽ����ʵ��
	 *�������: ��
	 *�������: ��
	 *����ֵ: xmlConfig����,��NULLΪ�ɹ�,NULLΪʧ��
	*/
	static xmlConfig *GetInstance();

	/*
	 *��������: Destroy Instance
	 *�������: ��
	 *�������: ��
	 *����ֵ: ��
	*/
	void DestroyInstance();

	/*
	 *��������: ����xml���������ļ�
	 *�������: strXmlFileName:�����ļ���
	 *�������: ��
	 *����ֵ: bool����,trueΪ�ɹ�,falseΪʧ��
	*/
	bool LoadConfig(const std::string &strXmlFileName);

	/*
	 *��������: ��ʼ��һ��xml�ڵ��ȱʡֵ
	 *�������: 
	 *			strTag:����const string &,һ��xml�ڵ��tag��ǩ,��<Item>Value</Item>�ڵ�, strTag=="Item",
	 *				   �����Ƕ�׽ڵ�,��<Item><ChildItem>Value</ChildItem></Item>,strTag=="Item.ChildItem"
	 *				   strTag�ĳ��ȱ���С��512�ֽ�
	 *			strDefaultValue:����const string &,�ڵ�strTag��ȱʡֵValue
	 *�������: ��
	 *����ֵ: ��
	*/
	void AddNodeDefaultValue(const std::string &strTag, const std::string &strDefaultValue);

	/*
	 *��������: ��ʼ��һ��xml�ڵ��ȱʡֵ
	 *�������: 
	 *			strTag:����const string &,һ��xml�ڵ��tag��ǩ,��<Item>Value</Item>�ڵ�, strTag=="Item",
	 *				   �����Ƕ�׽ڵ�,��<Item><ChildItem>Value</ChildItem></Item>,strTag=="Item.ChildItem"
	 *				   strTag�ĳ��ȱ���С��512�ֽ�
	 *			nDefaultValue:����const int &,�ڵ�strTag��ȱʡֵValue
	 *�������: ��
	 *����ֵ: ��
	*/
	void AddNodeDefaultValue(const std::string &strTag, const int &nDefaultValue);

	/*
	 *��������: ��ʼ��һ��xml�ڵ��ȱʡֵ
	 *�������: 
	 *			strTag:����const string &,һ��xml�ڵ��tag��ǩ,��<Item>Value</Item>�ڵ�, strTag=="Item",
	 *				   �����Ƕ�׽ڵ�,��<Item><ChildItem>Value</ChildItem></Item>,strTag=="Item.ChildItem"
	 *				   strTag�ĳ��ȱ���С��512�ֽ�
	 *			bDefaultValue:����const bool &,�ڵ�strTag��ȱʡֵValue
	 *�������: ��
	 *����ֵ: ��
	*/
	void AddNodeDefaultValue(const std::string &strTag, const bool &bDefaultValue);

	/*
	 *��������: ��ȡһ��xml�ڵ��ֵ
	 *�������: 
	 *			strTag:����const string &,һ��xml�ڵ��tag��ǩ,��<Item>Value</Item>�ڵ�, strTag=="Item",
	 *				   �����Ƕ�׽ڵ�,��<Item><ChildItem>Value</ChildItem></Item>,strTag=="Item.ChildItem"
	 *				   strTag�ĳ��ȱ���С��512�ֽ�
	 *�������: ��
	 *����ֵ: string����, �ڵ�strTag��ֵValue
	*/
	std::string GetNodeValueString(const std::string &strTag);

	/*
	 *��������: ��ȡһ��xml�ڵ��ֵ
	 *�������: 
	 *			strTag:����const string &,һ��xml�ڵ��tag��ǩ,��<Item>Value</Item>�ڵ�, strTag=="Item",
	 *				   �����Ƕ�׽ڵ�,��<Item><ChildItem>Value</ChildItem></Item>,strTag=="Item.ChildItem"
	 *				   strTag�ĳ��ȱ���С��512�ֽ�
	 *�������: ��
	 *����ֵ: int����, �ڵ�strTag��ֵValue
	*/
	int GetNodeValueInt(const std::string &strTag);

	/*
	 *��������: ��ȡһ��xml�ڵ��ֵ
	 *�������: 
	 *			strTag:����const string &,һ��xml�ڵ��tag��ǩ,��<Item>Value</Item>�ڵ�, strTag=="Item",
	 *				   �����Ƕ�׽ڵ�,��<Item><ChildItem>Value</ChildItem></Item>,strTag=="Item.ChildItem"
	 *				   strTag�ĳ��ȱ���С��512�ֽ�
	 *�������: ��
	 *����ֵ: bool����, �ڵ�strTag��ֵValue
	*/
	bool GetNodeValueBool(const std::string &strTag);

private:
	/*
	 *��������: �յ����¼��������ļ��ź�ʱ�����¼���xml���������ļ�
	 *�������: ��
	 *�������: ��
	 *����ֵ: bool����,trueΪ�ɹ�,falseΪʧ��
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
