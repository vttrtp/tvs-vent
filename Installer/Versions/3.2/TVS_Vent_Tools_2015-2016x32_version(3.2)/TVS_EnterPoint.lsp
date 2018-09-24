
(defun Load_TVS_Pipe (/)
(setq cmdeho (getvar "cmdecho"))
(setvar "cmdecho" 0)

 (arxload "TVSTVS_Ventilation_DBX.dbx")
(arxload "TVSTVS_Ventilation_ARX.arx") 

  (_kpblc-linetype-load "tvs_centerline" "TVS_LineType.lin")
(_kpblc-linetype-load "tvs_hidden" "TVS_LineType.lin")
(_kpblc-linetype-load "tvs_zigzag" "TVS_LineType.lin")
(setvar "cmdecho" cmdeho)

  )
;|==================================================�===========================
*    ������� ��������� ���� ����� � ������� ����. ��������� ���������
* ����������� �������.
*    ��������� ������:
*  ltype-name  ��� ���� ����� ��� ���������� ������
*  ltype-file  ��� ����� �������� ���� �����. nil -> "acadiso.lin"�
*      ���� ���� � ��������� ���� ����� �� ����� �� �����
*      ��������� ����, ���� ��������� ������ ���� � ����.
*    ������� ������:
(_kpblc-linetype-load "center" nil)  ; ��� ������� ������ ���������� ������ � ����������
                                     ; t ��� ������
***  ������������ ������������ ����� �������������� �������� ������� ltype_list
*** ������� ����� � ����� ��������� :) ������ ���� ���� ��� ������ �������
*** �������, ���� ������ ��������� ������� � ������� �������.
***  ��� ����� "Continuous" ��������� �� ������������ - �� ���� �� ���� �������
==================================================�===========================|;
(defun _kpblc-linetype-load
       (ltype-name ltype-file / ltype_normal ltype_list result)
  (vl-load-com)
  (setq ltype_list '(("center" . "������")
		     ("tvs_centerline" . "tvs_centerline")
		     ("tvs_hidden" . "tvs_hidden")	
		     ("tvs_zigzag" . "tvs_zigzag")				 
                     ("center2" . "������2")
                     ("hidden" . "���������")
                     ("hidden2" . "���������2")
                     )
        ltype-name (strcase ltype-name t)
        ) ;_ end of setq
  (if (not ltype-file)
    (setq ltype-file "acadiso.lin")
    ) ;_ end of if
  (if (vl-string-search "419" (vlax-product-key))
    ;; ������� ������, ������ ��� ���� �����
    (setq ltype_normal (cdr (assoc ltype-name ltype_list)))
    (setq ltype_normal ltype-name)
    ) ;_ end of if
  (if (not (tblsearch "ltype" ltype_normal))
    ;; ��� ����� �� ������, ���� ��� ���������. ��� ����� ������ ����
    ;; ������ � �����
    (setq result (not (vl-catch-all-error-p
                        (vl-catch-all-apply
                          'vla-load
                          (list
                            (vlax-get-property
                              (vla-get-activedocument (vlax-get-acad-object))
                              'linetypes
                              ) ;_ end of vlax-get-property
                            ltype_normal
                            ltype-file
                            ) ;_ end of list
                          ) ;_ end of vl-catch-all-apply
                        ) ;_ end of vl-catch-all-error-p
                      ) ;_ end of not
          ) ;_ end of setq
    ) ;_ end of if
  result
  ) ;_ end of defun


(Load_TVS_Pipe)
  (princ)