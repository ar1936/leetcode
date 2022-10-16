select b.name as Employee from employee a inner join employee b on a.id = b.managerId where a.salary < b.salary;  
