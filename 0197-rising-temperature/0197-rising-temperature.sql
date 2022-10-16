select a.id from weather a , weather b  where a.temperature> b.temperature and TO_DAYS(a.recordDate)-TO_DAYS(b.recordDate)=1;

