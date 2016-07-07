
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
;|==================================================­===========================
*    Функция подгрузки типа линии в текущий файл. Учитывает возможную
* локализацию системы.
*    Параметры вызова:
*  ltype-name  имя типа линии для английской версии
*  ltype-file  имя файла описания типа линии. nil -> "acadiso.lin"ю
*      Если файл с описанием типа линии не лежит по путям
*      поддержки када, надо указывать полный путь к нему.
*    Примеры вызова:
(_kpblc-linetype-load "center" nil)  ; для русской версии подгружает Осевая и возвращает
                                     ; t при успехе
***  Соответствие наименований линий обеспечивается огромным списком ltype_list
*** который можно и нужно дополнять :) Только надо либо все делать мелкими
*** буквами, либо жестко соблюдать регистр в моменты вызовов.
***  Тип линии "Continuous" обработке не подвергается - он есть во всех версиях
==================================================­===========================|;
(defun _kpblc-linetype-load
       (ltype-name ltype-file / ltype_normal ltype_list result)
  (vl-load-com)
  (setq ltype_list '(("center" . "осевая")
		     ("tvs_centerline" . "tvs_centerline")
		     ("tvs_hidden" . "tvs_hidden")	
		     ("tvs_zigzag" . "tvs_zigzag")				 
                     ("center2" . "осевая2")
                     ("hidden" . "невидимая")
                     ("hidden2" . "невидимая2")
                     )
        ltype-name (strcase ltype-name t)
        ) ;_ end of setq
  (if (not ltype-file)
    (setq ltype-file "acadiso.lin")
    ) ;_ end of if
  (if (vl-string-search "419" (vlax-product-key))
    ;; Русская версия, меняем имя типа линии
    (setq ltype_normal (cdr (assoc ltype-name ltype_list)))
    (setq ltype_normal ltype-name)
    ) ;_ end of if
  (if (not (tblsearch "ltype" ltype_normal))
    ;; тип линии не найден, надо его загрузить. Тип линии должен быть
    ;; описан в файле
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