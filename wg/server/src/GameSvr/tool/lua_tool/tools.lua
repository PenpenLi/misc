--������д������sql�ļ�
--@param tb ��Ҫ��������������
function output_dbsql(tb)
	local zone_id = string.format('%03d', tb.zone_id)
	for k, v in ipairs(tb) do
		--����ͨ������滻
		local output_file = string.gsub(v.output_file, '$<zoneid>', zone_id)
		local table_name = string.gsub(v.table_name, '$<zoneid>', zone_id)
		table_name = string.gsub(v.table_name, '$<zoneid>', zone_id)
		if v.table_id ~= nil then
			local table_id = string.format('%d', v.table_id)
			table_name = string.gsub(table_name, '$<tableid>', table_id)
			output_file = string.gsub(output_file, '$<tableid>', table_id)
		end
		
		--����ֶεĶ���
		local has_first = false
		local sql_outstr = ''
		sql_outstr = sql_outstr..'DROP TABLE IF EXISTS '..table_name..';\n'
		sql_outstr = sql_outstr..'SET @saved_cs_client     = @@character_set_client;\n'
		sql_outstr = sql_outstr..'SET character_set_client = utf8;\n'
		sql_outstr = sql_outstr..'CREATE TABLE '..table_name..' (\n'
		for kk, vv in ipairs(v) do
			if has_first then
				sql_outstr = sql_outstr..',\n'
			else
				has_first = true
			end
			sql_outstr = sql_outstr..'\t`'..vv.field..'` '..vv.attr
		end
		
		--����ؼ��ֵĶ���
		for kk, vv in ipairs(v) do
			if vv.keytype == 'PRIMARY' then
				sql_outstr = sql_outstr..',\n\tPRIMARY KEY(`'..vv.field..'`)'
			elseif vv.keytype == 'UNIQUE' then
				sql_outstr = sql_outstr..',\n\tUNIQUE KEY `'..vv.field..'` (`'..vv.field..'`)'
			end
		end
		sql_outstr = sql_outstr..'\n)ENGINE=InnoDB DEFAULT CHARSET=utf8;\n'
		sql_outstr = sql_outstr..'SET character_set_client = @saved_cs_client;\n'
		
		--д���ļ���
		local sql_outfile = assert(io.open(output_file, "w"))
		sql_outfile:write(sql_outstr)
		
		--д�븽�ӵ�sql���
		if v.append_sql ~= nil then
			sql_outfile:write(v.append_sql)
		end
		
		sql_outfile:close()
		print('create '..output_file..' ok!')
	end
end

--��������
if package.loaded['tools'] == nil and package.loaded['lua_tool.tools'] == nil then
	print('***���ܶ������У�')
end