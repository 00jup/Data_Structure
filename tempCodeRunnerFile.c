fp = fopen("data.txt", "rt");
  // if (fp == NULL)
  // {
  //   printf("File not found\n");
  //   return 0;
  // }
  // // 파일로부터 데이터 입력 받아 tmp 노드에 저장후 노드 삽입
  // while (!feof(fp))
  // {
  //   fscanf(fp, "%d %s %d %d %d %d", &dat.num, dat.name, &dat.kor, &dat.math, &dat.eng, &dat.com);
  //   printf("%6d %10s %6d %6d %6d %6d\n", dat.num, dat.name, dat.kor, dat.math, dat.eng, dat.com);
  //   tmp = (DListNode *)malloc(sizeof(DListNode)); // create_node 함수 구현 대신 파일 내에서 생성
  //   tmp->data = dat;
  //   dinsert_node(head, tmp); // head에 새로 만든 tmp를 insert
  // }