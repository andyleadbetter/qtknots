import Qt 4.7

    XmlListModel {
        id: xmlFiles
        query: "/root/items/item"

        XmlRole { name: "dirname"; query: "dirname/string()" }
        XmlRole { name: "dir"; query: "dir/string()" }
        XmlRole { name: "id"; query: "id/string()" }
        XmlRole { name: "category"; query: "category/string()" }
        XmlRole { name: "mid"; query: "mid/string()" }
        XmlRole { name: "search"; query: "search/string()" }
        XmlRole { name: "virtual"; query: "virtual/string()" }
        XmlRole { name: "name"; query: "name/string()" }
        XmlRole { name: "duration"; query: "duration/string()" }
        XmlRole { name: "added"; query: "added/string()" }
        XmlRole { name: "views"; query: "views/string()" }
        XmlRole { name: "rating"; query: "rating/string()" }
        XmlRole { name: "video_width"; query: "width/string()" }
        XmlRole { name: "video_height"; query: "height/string()" }
        XmlRole { name: "mediatype"; query: "mediatype/string()" }
    }

/***
  Root Document consists of
<root>
  <items>
    <item>
      <id>2</id>
      <category><![CDATA[Music]]></category>
      <mid>1</mid>
    </item>
    <item>
      <id>3</id>
      <category><![CDATA[Pictures]]></category>
      <mid>11</mid>
    </item>
    <item>
      <id>1</id>
      <category><![CDATA[Videos]]></category>
      <mid>2</mid>
    </item>
    <item>
      <id>1</id>
      <virtual><![CDATA[Latest]]></virtual>
      <search><![CDATA[SELECT media.*,null AS mid FROM media WHERE active = 1 ORDER BY added DESC]]></search>
      <mid>3</mid>
    </item>
    <item>
      <id>3</id>
      <virtual><![CDATA[Random]]></virtual>
      <search><![CDATA[SELECT media.*,null AS mid FROM media WHERE active = 1 ORDER BY RANDOM()]]></search>
      <mid>4</mid>
    </item>
    <item>
      <id>2</id>
      <virtual><![CDATA[Unfinished]]></virtual>
      <search><![CDATA[SELECT media.*,null AS mid FROM media WHERE active = 1 AND position > 0.0 ORDER BY position DESC]]></search>
      <mid>9</mid>
    </item>
    <item>
      <id>5</id>
      <virtual><![CDATA[Unlistened]]></virtual>
      <search><![CDATA[SELECT media.*,null AS mid FROM media WHERE active = 1 AND mediatype = 1 AND views = 0 ORDER BY added DESC]]></search>
      <mid>10</mid>
    </item>
    <item>
      <id>4</id>
      <virtual><![CDATA[Unviewed]]></virtual>
      <search><![CDATA[SELECT media.*,null AS mid FROM media WHERE active = 1 AND mediatype <> 1 AND views = 0 ORDER BY added DESC]]></search>
      <mid>7</mid>
    </item>
    <item>
      <dir><![CDATA[/]]></dir>
      <dirname><![CDATA[Browse by path]]></dirname>
      <id>0</id>
    </item>
  </items>
  <pages>
    <current>1</current>
    <total>1</total>
  </pages>
</root>
*/
