CREATE OR REPLACE TRIGGER salary_difference_trigger
BEFORE INSERT OR UPDATE OR DELETE ON customers
FOR EACH ROW
DECLARE
 old_salary customers.salary%TYPE;
 new_salary customers.salary%TYPE;
BEGIN
 IF INSERTING OR UPDATING THEN
 old_salary := NVL(:OLD.salary, 0); -- Get the old salary, handle NULL 
value
 new_salary := NVL(:NEW.salary, 0); -- Get the new salary, handle NULL 
value
 DBMS_OUTPUT.PUT_LINE('Salary Difference: ' || (new_salary -
old_salary));
 ELSIF DELETING THEN
 old_salary := NVL(:OLD.salary, 0); -- Get the old salary, handle NULL 
value
 DBMS_OUTPUT.PUT_LINE('Salary Difference: ' || -old_salary);
 END IF;
END;
--set serveroutput on;
--update customers
--  set salary=65000
--  where id=123
