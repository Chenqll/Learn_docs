```python

libai

(Pdb) p examples[0]
InputExample(guid='train-1', text_a=['1', '9', '6', '6', '年', '出', '生', '，', '汉', '族', '，', '中', '共', '党', '员', '，', '本', '科', '学', '历', '，', '工', '程', '师', '、', '美', '国', '项', '目', '管', '理', '协', '会', '注', '册', '会', '员', '（', 'P', 'M', 'I', 'M', 'e', 'm', 'b', 'e', 'r', '）', '、', '注', '册', '项', '目', '管', '理', '专', '家', '（', 'P', 'M', 'P', '）', '、', '项', '目', '经', '理', '。'], text_b=None, label=['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'B-RACE', 'I-RACE', 'O', 'B-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'O', 'B-EDU', 'I-EDU', 'I-EDU', 'I-EDU', 'O', 'B-TITLE', 'I-TITLE', 'I-TITLE', 'O', 'B-ORG', 'I-ORG', 'I-ORG', 'I-ORG', 'I-ORG', 'I-ORG', 'I-ORG', 'I-ORG', 'B-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'O', 'B-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'O', 'O', 'B-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'O', 'B-TITLE', 'I-TITLE', 'I-TITLE', 'O', 'O', 'B-TITLE', 'I-TITLE', 'I-TITLE', 'I-TITLE', 'O'])
```
```python

ner

(Pdb) p examples[0]
{
  "guid": "train-1",
  "labels": [
    "O",
    "O",
    "O",
    "O",
    "O",
    "O",
    "O",
    "O",
    "B-RACE",
    "I-RACE",
    "O",
    "B-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "O",
    "B-EDU",
    "I-EDU",
    "I-EDU",
    "I-EDU",
    "O",
    "B-TITLE",
    "I-TITLE",
    "I-TITLE",
    "O",
    "B-ORG",
    "I-ORG",
    "I-ORG",
    "I-ORG",
    "I-ORG",
    "I-ORG",
    "I-ORG",
    "I-ORG",
    "B-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "O",
    "B-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "O",
    "O",
    "B-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "O",
    "B-TITLE",
    "I-TITLE",
    "I-TITLE",
    "O",
    "O",
    "B-TITLE",
    "I-TITLE",
    "I-TITLE",
    "I-TITLE",
    "O"
  ],
  "text_a": [
    "1",
    "9",
    "6",
    "6",
    "\u5e74",
    "\u51fa",
    "\u751f",
    "\uff0c",
    "\u6c49",
    "\u65cf",
    "\uff0c",
    "\u4e2d",
    "\u5171",
    "\u515a",
    "\u5458",
    "\uff0c",
    "\u672c",
    "\u79d1",
    "\u5b66",
    "\u5386",
    "\uff0c",
    "\u5de5",
    "\u7a0b",
    "\u5e08",
    "\u3001",
    "\u7f8e",
    "\u56fd",
    "\u9879",
    "\u76ee",
    "\u7ba1",
    "\u7406",
    "\u534f",
    "\u4f1a",
    "\u6ce8",
    "\u518c",
    "\u4f1a",
    "\u5458",
    "\uff08",
    "P",
    "M",
    "I",
    "M",
    "e",
    "m",
    "b",
    "e",
    "r",
    "\uff09",
    "\u3001",
    "\u6ce8",
    "\u518c",
    "\u9879",
    "\u76ee",
    "\u7ba1",
    "\u7406",
    "\u4e13",
    "\u5bb6",
    "\uff08",
    "P",
    "M",
    "P",
    "\uff09",
    "\u3001",
    "\u9879",
    "\u76ee",
    "\u7ecf",
    "\u7406",
    "\u3002"
  ]
}
```

```python
ner

(Pdb) p example.text_a
['1', '9', '6', '6', '年', '出', '生', '，', '汉', '族', '，', '中', '共', '党', '员', '，', '本', '科', '学', '历', '，', '工', '程', '师', '、', '美', '国', '项', '目', '管', '理', '协', '会', '注', '册', '会', '员', '（', 'P', 'M', 'I', 'M', 'e', 'm', 'b', 'e', 'r', '）', '、', '注', '册', '项', '目', '管', '理', '专', '家', '（', 'P', 'M', 'P', '）', '、', '项', '目', '经', '理', '。']

if isinstance(example.text_a,list):
            example.text_a = " ".join(example.text_a)

(Pdb) p example.text_a
'1 9 6 6 年 出 生 ， 汉 族 ， 中 共 党 员 ， 本 科 学 历 ， 工 程 师 、 美 国 项 目 管 理 协 会 注 册 会 员 （ P M I M e m b e r ） 、 注 册 项 目 管 理 专 家 （ P M P ） 、 项 目 经 理 。'
```
