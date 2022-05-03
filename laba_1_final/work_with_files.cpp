#include "work_with_files.h"

void add_value_in_ir(InvoiceReferences &invoice_references,int &pos_in_ir,QString &value){
    if (pos_in_ir == 1){
        invoice_references.set_type(value);
    }
    else if (pos_in_ir == 2){
        invoice_references.set_id(value.toInt());
    }
    else if (pos_in_ir == 3){
        invoice_references.set_name(value);
    }
    else if (pos_in_ir == 4){
        invoice_references.set_unit_of_measurement(value);
    }
    else if (pos_in_ir == 5){
        invoice_references.set_count(value.toInt());
    }
    else if (pos_in_ir == 6){
        invoice_references.set_price(value.toDouble());
    }
    else{
        invoice_references.set_current_sum(value.toDouble());
    }
    pos_in_ir++;
}

void add_value_in_er(EmployeeReferences &employee_references,int &pos_in_er,QString &value){
    if (pos_in_er == 1){
        employee_references.set_name(value);
    }
    else if (pos_in_er == 2){
        employee_references.set_post(value);
    }
    else if (pos_in_er == 3){
        employee_references.set_salary(value.toDouble());
    }
    pos_in_er++;
}

void add_value_in_aft(AccoutingForTheReceiptAndDeliveryOfGoods &accouting_for_the_receipt_and_delivery_of_goods,int &pos_in_aft,QString &value){
    if (pos_in_aft == 1){
        accouting_for_the_receipt_and_delivery_of_goods.set_name(value);
    }
    else if (pos_in_aft == 2){
        accouting_for_the_receipt_and_delivery_of_goods.set_coming(value.toInt());
    }
    else if (pos_in_aft == 3){
        accouting_for_the_receipt_and_delivery_of_goods.set_expenditure(value.toInt());
    }
    else if (pos_in_aft == 4){
        accouting_for_the_receipt_and_delivery_of_goods.set_price(value.toDouble());
    }
    else if (pos_in_aft == 5){
        accouting_for_the_receipt_and_delivery_of_goods.set_current_sum(value.toDouble());
    }
    pos_in_aft++;
}

void add_value_in_pr(ProductReferences &product_references,int &pos_in_pr,QString &value){
    if (pos_in_pr == 1){
        product_references.set_name(value);
    }
    else if (pos_in_pr == 2){
        product_references.set_product_code(value.toInt());
    }
    else if (pos_in_pr == 3){
        product_references.set_product_type_code(value.toInt());
    }
    else if (pos_in_pr == 4){
        product_references.set_provider(value);
    }
    else if (pos_in_pr == 5){
        product_references.set_count(value.toInt());
    }
    pos_in_pr++;
}
void work_with_files::read_file(QList <InvoiceReferences> &invoice_references,QList <EmployeeReferences> &employee_references,QList <AccoutingForTheReceiptAndDeliveryOfGoods> &accouting_for_the_receipt_and_delivery_of_goods,QList <ProductReferences> &product_references){
    QTextStream out(stdout);
    QString fileName = QFileDialog::getOpenFileName();
    fileIn.setFileName(fileName);
    fileIn.open(QIODevice::ReadOnly | QIODevice::Text);
    QString line = fileIn.readLine();
    bool was_item = false,was_ir = false,was_er = false,was_aft= false,was_pr = false;
    int pos_in_ir = 1,pos_in_er = 1,pos_in_aft = 1,pos_in_pr = 1;
    while(!fileIn.atEnd()){
        line = fileIn.readLine();
        QString cur_str = "";
        bool was_ch = false;
        for (int i = 0;i < line.size();i++){
            if (!was_ch){
                if (line[i] == ' ') continue;
                if (line[i] == '<'){
                    was_ch = true;
                    continue;
                }
            }
            else{
                if (!was_item){
                    if (line[i] == '>'){
                        if (cur_str == "item") was_item = true;
                        cur_str = "";
                        continue;
                    }
                    else cur_str += line[i];
                }
                else{
                    if (was_ir){
                        if (line[i] == ' ' || line[i] == '>'){
                            bool was_find_information = false;
                            QString cur_value = "";
                            if (cur_str == "/invoice_reference"){
                                was_ir = false;
                                pos_in_ir = 1;
                            }
                            if (cur_str == "value"){
                                was_find_information = true;
                                for (int j = i + 4;j < line.size();j++){
                                    if (line[j] == '"') break;
                                    cur_value += line[j];
                                }
                            }
                            else if (cur_str == "name"){
                                was_find_information = true;
                                for (int j = i + 1;j < line.size();j++){
                                    if (line[j] == '<') break;
                                    cur_value += line[j];
                                }
                            }
                            if (was_find_information){
                                add_value_in_ir(invoice_references[invoice_references.size() - 1],pos_in_ir,cur_value);
                            }
                            cur_str = "";
                            continue;
                        }
                        else cur_str += line[i];
                    }
                    else if (was_er){
                        if (line[i] == ' ' || line[i] == '>'){
                            bool was_find_information = false;
                            QString cur_value = "";
                            if (cur_str == "/employee_reference"){
                                was_er = false;
                                pos_in_er = 1;
                            }
                            if (cur_str == "value"){
                                was_find_information = true;
                                for (int j = i + 4;j < line.size();j++){
                                    if (line[j] == '"') break;
                                    cur_value += line[j];
                                }
                            }
                            else if (cur_str == "name"){
                                was_find_information = true;
                                for (int j = i + 1;j < line.size();j++){
                                    if (line[j] == '<') break;
                                    cur_value += line[j];
                                }
                            }
                            if (was_find_information){
                                add_value_in_er(employee_references[employee_references.size() - 1],pos_in_er,cur_value);
                            }
                            //out << cur_str << "\n";
                            cur_str = "";
                            continue;
                        }
                        else cur_str += line[i];
                    }
                    else if (was_aft){
                        if (line[i] == ' ' || line[i] == '>'){
                            //out << cur_str << "\n";
                            bool was_find_information = false;
                            QString cur_value = "";
                            if (cur_str == "/accouting_for_the_receipt_and_delivery_of_goods"){
                                was_aft = false;
                                pos_in_aft = 1;
                            }
                            if (cur_str == "value"){
                                was_find_information = true;
                                for (int j = i + 4;j < line.size();j++){
                                    if (line[j] == '"') break;
                                    cur_value += line[j];
                                }
                            }
                            else if (cur_str == "name"){
                                was_find_information = true;
                                for (int j = i + 1;j < line.size();j++){
                                    if (line[j] == '<') break;
                                    cur_value += line[j];
                                }
                            }
                            if (was_find_information){
                                add_value_in_aft(accouting_for_the_receipt_and_delivery_of_goods[accouting_for_the_receipt_and_delivery_of_goods.size() - 1],pos_in_aft,cur_value);
                            }
                            cur_str = "";
                            continue;
                        }
                        else cur_str += line[i];
                    }
                    else if (was_pr){
                        if (line[i] == ' ' || line[i] == '>'){
                            //out << cur_str << "\n";
                            bool was_find_information = false;
                            QString cur_value = "";
                            if (cur_str == "/product_reference"){
                                was_pr = false;
                                pos_in_pr = 1;
                            }
                            if (cur_str == "value"){
                                was_find_information = true;
                                for (int j = i + 4;j < line.size();j++){
                                    if (line[j] == '"') break;
                                    cur_value += line[j];
                                }
                            }
                            else if (cur_str == "name"){
                                was_find_information = true;
                                for (int j = i + 1;j < line.size();j++){
                                    if (line[j] == '<') break;
                                    cur_value += line[j];
                                }
                            }
                            if (was_find_information){
                                add_value_in_pr(product_references[product_references.size() - 1],pos_in_pr,cur_value);
                            }
                            cur_str = "";
                            continue;
                        }
                        else cur_str += line[i];
                    }
                    else{
                        if (line[i] == '>'){
                            //out << cur_str << "\n";
                            if (cur_str == "invoice_reference"){
                                InvoiceReferences temp;
                                invoice_references.append(temp);
                                was_ir = true;
                            }
                            else if (cur_str == "employee_reference"){
                                EmployeeReferences temp;
                                employee_references.append(temp);
                                was_er = true;
                            }
                            else if (cur_str == "accouting_for_the_receipt_and_delivery_of_goods"){
                                AccoutingForTheReceiptAndDeliveryOfGoods temp;
                                accouting_for_the_receipt_and_delivery_of_goods.append(temp);
                                was_aft = true;
                            }
                            else if (cur_str == "product_reference"){
                                ProductReferences temp;
                                product_references.append(temp);
                                was_pr = true;
                            }
                            else if (cur_str == "/item"){
                                was_item = false;
                            }
                            cur_str = "";
                            continue;
                        }
                        else cur_str += line[i];
                    }
                }
            }
        }
    }
    fileIn.close();
}

void work_with_files::write_in_file(QList<InvoiceReferences> &invoice_references, QList<EmployeeReferences> &employee_references, QList<AccoutingForTheReceiptAndDeliveryOfGoods> &accouting_for_the_receipt_and_delivery_of_goods, QList<ProductReferences> &product_reference){
    QString fileName = QFileDialog::getSaveFileName();
    fileOut.setFileName(fileName);
    fileOut.open(QIODevice::WriteOnly);
    QTextStream out_file; out_file.setDevice(&fileOut);
    out_file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    out_file << "<items>\n";
    int pos = 0;
    while(pos < invoice_references.size()){
        out_file << "    <item>\n";
        out_file << "        <invoice_reference>\n";
        QString start = "            ";
        for (int pos_in_ir = 1;pos_in_ir <= 7;pos_in_ir++){
            out_file << start;
            if (pos_in_ir == 1) out_file << "<type value = \"" << QVariant(invoice_references[pos].get_type()).toString() << "\"/>\n";
            else if (pos_in_ir == 2) out_file << "<id value = \"" << QVariant(invoice_references[pos].get_id()).toString() << "\"/>\n";
            else if (pos_in_ir == 3) out_file << "<name>" << QVariant(invoice_references[pos].get_name()).toString() << "</name>\n";
            else if (pos_in_ir == 4) out_file << "<unit_of_measurement value = \"" << QVariant(invoice_references[pos].get_unit_of_measurement()).toString() << "\"/>\n";
            else if (pos_in_ir == 5) out_file << "<count value = \"" << QVariant(invoice_references[pos].get_count()).toString() << "\"/>\n";
            else if (pos_in_ir == 6) out_file << "<price value = \"" << QVariant(invoice_references[pos].get_price()).toString() << "\"/>\n";
            else if (pos_in_ir == 7) out_file << "<current_sum value = \"" << QVariant(invoice_references[pos].get_current_sum()).toString() << "\"/>\n";
        }
        out_file << "        </invoice_reference>\n";
        out_file << "        <employee_reference>\n";
        for (int pos_in_pr = 1;pos_in_pr <= 3;pos_in_pr++){
            out_file << start;
            if (pos_in_pr == 1) out_file << "<name>" << QVariant(employee_references[pos].get_name()).toString() << "</name>\n";
            else if (pos_in_pr == 2) out_file << "<post value = \"" << QVariant(employee_references[pos].get_post()).toString() << "\"/>\n";
            else if (pos_in_pr == 3) out_file << "<salary value = \"" << QVariant(employee_references[pos].get_salary()).toString() << "\"/>\n";
        }
        out_file << "        </employee_reference>\n";
        out_file << "        <accouting_for_the_receipt_and_delivery_of_goods>\n";
        for (int pos_in_aft = 1;pos_in_aft <= 5;pos_in_aft++){
            out_file << start;
            if (pos_in_aft == 1) out_file << "<name>" << QVariant(accouting_for_the_receipt_and_delivery_of_goods[pos].get_name()).toString() << "</name>\n";
            else if (pos_in_aft == 2) out_file << "<coming value = \"" << QVariant(accouting_for_the_receipt_and_delivery_of_goods[pos].get_coming()).toString() << "\"/>\n";
            else if (pos_in_aft == 3) out_file << "<expenditure value = \"" << QVariant(accouting_for_the_receipt_and_delivery_of_goods[pos].get_expenditure()).toString() << "\"/>\n";
            else if (pos_in_aft == 4) out_file << "<price value = \"" << QVariant(accouting_for_the_receipt_and_delivery_of_goods[pos].get_price()).toString() << "\"/>\n";
            else if (pos_in_aft == 5) out_file << "<current_sum value = \"" << QVariant(accouting_for_the_receipt_and_delivery_of_goods[pos].get_current_sum()).toString() << "\"/>\n";
        }
        out_file << "        </accouting_for_the_receipt_and_delivery_of_goods>\n";
        out_file << "        <product_reference>\n";
        for (int pos_in_pr = 1;pos_in_pr <= 5;pos_in_pr++){
            out_file << start;
            if (pos_in_pr == 1) out_file << "<name>" << QVariant(product_reference[pos].get_name()).toString() << "</name>\n";
            else if (pos_in_pr == 2) out_file << "<product_code value = \"" << QVariant(product_reference[pos].get_product_code()).toString() << "\"/>\n";
            else if (pos_in_pr == 3) out_file << "<product_type_code value = \"" << QVariant(product_reference[pos].get_product_type_code()).toString() << "\"/>\n";
            else if (pos_in_pr == 4) out_file << "<provider value = \"" << QVariant(product_reference[pos].get_provider()).toString() << "\"/>\n";
            else if (pos_in_pr == 5) out_file << "<count value = \"" << QVariant(product_reference[pos].get_count()).toString() << "\"/>\n";
        }
        out_file << "        </product_reference>\n";
        out_file << "    </item>\n";
        pos++;
    }
    out_file << "</items>";
    fileOut.close();
}
