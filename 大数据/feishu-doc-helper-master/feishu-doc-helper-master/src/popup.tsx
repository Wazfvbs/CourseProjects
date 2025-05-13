import React, { useState, useEffect } from 'react';
import { Card, Typography, Button, Popover, Cascader } from 'antd';
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faBilibili, faTiktok, faWeixin } from '@fortawesome/free-brands-svg-icons';
import { cascaderData } from '~contents/content-core';

const { Paragraph } = Typography;


const AboutPageContent = () => {
  const popoverContent = {
    github: "三此君 GitHub",
    bilibili: <img src="https://img2023.cnblogs.com/blog/2740513/202305/2740513-20230530083651756-1915761883.jpg" alt="视频B站首发" style={{ width: '150px', height: '150px' }} />,
    tiktok: <img src="https://img2023.cnblogs.com/blog/2740513/202305/2740513-20230529203236662-1716684994.jpg" alt="抖音" style={{ width: '150px', height: '150px' }} />,
    gzh: <img src="https://img2023.cnblogs.com/blog/2740513/202305/2740513-20230529203219168-2117666216.jpg" alt="公众号" style={{ width: '150px', height: '150px' }} />,
    wechat: <img src="https://img2023.cnblogs.com/blog/2740513/202305/2740513-20230529203303815-1142190090.jpg" alt="微信号" style={{ width: '150px', height: '150px' }} />,
  };

  const openLink = (url) => {
    chrome.tabs.create({ url });
  };

  return (
    <div style={{ padding: '10px', width: '350px' }}>
      <Paragraph style={{ fontSize: '15px', padding: '5px' }}>
        感谢支持！
        <br />
        如果觉得本工具不错，请分享给你的朋友！
        <br />
        有任何问题也可以私信三此君，交个朋友。
      </Paragraph>

      <div style={{ display: 'flex' }}>
        <Button onClick={() => openLink("https://github.com/sancijun/feishu-doc-helper#readme")} style={{ marginRight: '8px', marginLeft: '5px' }}>
          使用说明
        </Button>
        <Button type="primary" ghost onClick={() => openLink("https://github.com/sancijun/feishu-doc-helper/issues/new?assignees=&labels=enhancement&projects=&template=---feature.md&title=%5BFeature%5D+")} style={{ marginRight: '8px' }}>
          功能建议
        </Button>
        <Button danger onClick={() => openLink("https://github.com/sancijun/feishu-doc-helper/issues/new?assignees=&labels=&projects=&template=---bug.md&title=%5BBug%5D+")}>
          缺陷反馈
        </Button>
      </div>

      <div style={{ display: 'flex', marginTop: '12px' }}>
        <Popover content={popoverContent.wechat} title="三此君微信号">
          <Button type="text" style={{ padding: '5px', fontSize: '13px' }}>
            联系作者：微信
          </Button>
        </Popover>
        <Popover content={popoverContent.bilibili} title="视频在B站首发">
          <Button type="text" icon={<FontAwesomeIcon icon={faBilibili} />} onClick={() => openLink("https://space.bilibili.com/96271327/")} style={{ padding: '5px', fontSize: '13px' }}>
            B站
          </Button>
        </Popover>
        <Popover content={popoverContent.tiktok} title="三此君抖音号">
          <Button type="text" icon={<FontAwesomeIcon icon={faTiktok} />} onClick={() => openLink("https://v.douyin.com/UuXokgA/")} style={{ padding: '5px', fontSize: '13px' }}>
            抖音
          </Button>
        </Popover>
        <Popover content={popoverContent.gzh} title="三此君公众号">
          <Button type="text" icon={<FontAwesomeIcon icon={faWeixin} />} style={{ padding: '5px', fontSize: '13px' }}>
            公众号
          </Button>
        </Popover>
      </div>
    </div>
  );
}


function SettingsPageContent() {

  const [cascaderOptions, setCascaderOptions] = useState();
  const [selectedValue, setSelectedValue] = useState([]);

  useEffect(() => {
    chrome.storage.local.get(
      ["feishuFolderList", "roamExcludeFolder"],
      (result) => {
        const { feishuFolderList, roamExcludeFolder } = result;
        setCascaderOptions(cascaderData(feishuFolderList))
        setSelectedValue(roamExcludeFolder)
      }
    );
  }, []);

  const handleCascaderChange = (value, selectedOptions) => {
    setSelectedValue(value);
    chrome.storage.local.set({ 'roamExcludeFolder': value });
    console.log('roamExcludeFolder', value)
  };

  return (
    <>
      <Paragraph style={{ fontSize: '15px', padding: '5px' }}>
        选择文档漫游需要排除的目录，文档漫游时，选中目录下的文档将不会被打开。
      </Paragraph>
      <Cascader options={cascaderOptions} multiple onChange={handleCascaderChange} placeholder="选择文档漫游需要排除的目录" value={selectedValue} style={{ width: '100%', marginTop: '10px', marginBottom: '20px' }} />
    </>

  );
}

const tabList = [
  {
    key: 'tab1',
    tab: '关于',
  },
  {
    key: 'tab2',
    tab: '设置',
  },
];

const contentList: Record<string, React.ReactNode> = {
  tab1: <AboutPageContent />,
  tab2: <SettingsPageContent />,
};

const PopupPage: React.FC = () => {
  const [activeTabKey, setActiveTabKey] = useState<string>('tab1');

  const onTabChange = (key: string) => {
    setActiveTabKey(key);
  };

  return (
    <Card
      style={{ width: '350px' }}
      tabList={tabList.map(tab => ({
        ...tab,
        key: tab.key,
        tab: <div style={{ width: '125px', display: 'flex', justifyContent: 'center' }}>{tab.tab}</div>, // 设置标签宽度
      }))}
      activeTabKey={activeTabKey}
      onTabChange={onTabChange}
    >
      {contentList[activeTabKey]}

    </Card>
  );
};

export default PopupPage;
