create view advisor_student as (select * from advisor natural join student natural join instructor); 

set serveroutput on 
CREATE OR REPLACE TRIGGER l11q5
INSTEAD OF 
    DELETE 
ON advisor_student
FOR EACH ROW
BEGIN 
   DELETE FROM advisor where advisor.s_id=:old.s_id;
END;
/